import java.io.*;
import java.util.*;

public class LCA{

  static class Node{
    int data;
    Node left;
    Node right;

    Node(int data)
    {
      this.data = data;
      this.left= null;
      this.right = null;
    }
  }

  static Node root; // root node 
  static void create(){

    Scanner sc = new Scanner(System.in);
    int x;
    Node p, t;

    Queue<Node> q = new LinkedList<>();

    System.out.println("Enter the root ");
    x = sc.nextInt();
    root = new Node(x);
    q.add(root);

    while(!q.isEmpty()){

      p = q.poll();

      System.out.println("Enter the left node of "+p.data);
      x = sc.nextInt();

      if(x!=-1){
        t = new Node(x);
        p.left = t;
        q.add(t);
      }

      System.out.println("Enter the right node of "+p.data);
      x = sc.nextInt();
      if(x!=-1){
        t = new Node(x);
        p.right = t;
        q.add(t);
      }
    }
  }

  static Node Lc(int  n1, int  n2){

    Node lk = Lca(root, n1, n2);
    return lk;
  }

  static int find(Node root, int x, int y){
    Node temp = Lc(x, y);
    int lh = height(temp.left);
    int rh = height(temp.right);

    int res = lh+rh;
    return res;
  }

  static Node Lca(Node n, int n1, int n2){
    if(n==null){
      return null;
    }

    if(n.data == n1 || n.data == n2){
      return n;
    }

    Node lf = Lca(n.left, n1, n2);
    Node rf = Lca(n.right, n1 , n2);

    if(lf!=null && rf!=null){
      return n;
    }

    if(lf!=null){
      return lf;
    }
    else{
      return rf;
    }
  }

  static int height(Node root){
    if(root==null){
      return 0;
    }
    int lt = height(root.left);
    int rt = height(root.right);

    int res = Math.max(lt, rt)+1;
    return res;
  }
  public static void main(String[] args) {
   create();
   int xx = 4;
   int yy = 6;
   System.out.println(find(root, xx, yy));

  }
}
