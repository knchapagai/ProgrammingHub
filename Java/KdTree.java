import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.Stack;
import java.util.ArrayList;

public class KdTree {
    private static class Node 
    {
        private Point2D p;      // the point
        private final RectHV rect;    // the axis-aligned rectangle corresponding to this node
        private Node lb;        // the left/bottom subtree
        private Node rt;        // the right/top subtree
        private final boolean orient;  // true: vert; false: hori
       
        public Node(Point2D p, RectHV r, boolean orient)
        {
            this.p = p;
            this.orient = orient;
            this.lb = null;
            this.rt = null;
            this.rect = r;
        }
    }
    
    private Node root;
    private int count;

    public KdTree()
    {
        root = null;
        count = 0;
    }

    public boolean isEmpty()
    {
        return count == 0;
    }
    public int size()
    {
        return count;
    }
    public void insert(Point2D p)
    {
        if (p == null) throw new IllegalArgumentException();
        root = insert(root, p, root);
    }
    private Node insert(Node x, Point2D p, Node parent)
    {
        if (x == null)
        {   
            count++;
            if (parent == null) return new Node(p, new RectHV(0, 0, 1, 1), true);
            double xmin = parent.rect.xmin();
            double xmax = parent.rect.xmax();
            double ymin = parent.rect.ymin();
            double ymax = parent.rect.ymax();
            if (parent.orient)
            {
                if (compare(parent, p) < 0) xmin = parent.p.x();
                else xmax = parent.p.x(); 
            }
            else
            {
                if (compare(parent, p) < 0) ymin = parent.p.y();
                else ymax = parent.p.y();
            }
            RectHV rect = new RectHV(xmin, ymin, xmax, ymax);
            return new Node(p, rect, !parent.orient);
        }
        int cmp = compare(x, p);
        if (cmp > 0) x.lb = insert(x.lb, p, x);
        else if (cmp < 0) x.rt = insert(x.rt, p, x);
        else x.p = p;
        return x;
    }
    
    private int compare(Node node, Point2D p)
    {
        if (p.compareTo(node.p) == 0) return 0;
        if (node.orient && Point2D.X_ORDER.compare(node.p, p) < 0) return -1;
        else if (!node.orient && Point2D.Y_ORDER.compare(node.p, p) < 0) return -1;
        return 1;
    }
    public boolean contains(Point2D p)            // does the set contain point p? 
    {
        if (p == null) throw new IllegalArgumentException();
        return contains(root, p) != null;
    }
    private Point2D contains(Node x, Point2D p)
    {
        if (p == null) throw new IllegalArgumentException();
        if (x == null) return null;
        int cmp = compare(x, p);
        if (cmp < 0) return contains(x.rt, p);
        else if (cmp > 0) return contains(x.lb, p);
        else return x.p;        
    }
    public void draw()
    {
        if (root == null) return;
        draw(root);
    }
    private void draw(Node n)
    {
        if (n == null) return;

        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setPenRadius(0.01);
        n.p.draw();
        StdDraw.setPenRadius();
        if (n.orient)
        {
            StdDraw.setPenColor(StdDraw.RED);
            StdDraw.line(n.p.x(), n.rect.ymin(), n.p.x(), n.rect.ymax());
        }
        else
        {
            StdDraw.setPenColor(StdDraw.BLUE);
            StdDraw.line(n.rect.xmin(), n.p.y(), n.rect.xmax(), n.p.y());
        }
        draw(n.lb);
        draw(n.rt);
        
    }
    public Iterable<Point2D> range(RectHV rect)             // all points that are inside the rectangle (or on the boundary)
    {
        if (rect == null) throw new IllegalArgumentException();
        if (root == null) return null;
        ArrayList<Point2D> rangeList = new ArrayList<Point2D>();
        Queue<Node> searchQueue = new Queue<Node>();
        searchQueue.enqueue(root);
        while (!searchQueue.isEmpty())
        {
            Node n = searchQueue.dequeue();
            if (n.rect.intersects(rect))
            {
                if (rect.contains(n.p)) rangeList.add(n.p);
                if (n.lb != null) searchQueue.enqueue(n.lb);
                if (n.rt != null) searchQueue.enqueue(n.rt);
            }
        }
        return rangeList;
    }
    public Point2D nearest(Point2D p)
    {
        if (p == null) throw new IllegalArgumentException();
        if (isEmpty()) return null;
        Stack<Node> searchStack = new Stack<Node>();
        searchStack.push(root);

        double minDist = Double.POSITIVE_INFINITY;
        Point2D nearPoint = searchStack.peek().p;
        while (!searchStack.isEmpty())
        {
            Node n = searchStack.pop();
            double dist = n.rect.distanceSquaredTo(p);
            if (Double.compare(dist, minDist) < 0)
            {
                dist = n.p.distanceSquaredTo(p); 
                if (dist < minDist)
                {
                    nearPoint = n.p;
                    minDist = dist;
                }
                if (compare(n, p) < 0)
                {   
                    if (n.lb != null) searchStack.push(n.lb); 
                    if (n.rt != null) searchStack.push(n.rt);
                }
                else
                {
                    if (n.rt != null) searchStack.push(n.rt);
                    if (n.lb != null) searchStack.push(n.lb); 
                }
            } 
        }
        return nearPoint;
    }
   
    public static void main(String[] args)
    {
    }
}