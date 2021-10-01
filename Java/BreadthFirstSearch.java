import java.util.*;
public class BreadthFirstSearch {
    public static void main(String[] args) {
        int n, i, j;
        int f = 0, r = 0;
        System.out.println("Enter the number of nodes");
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int[][] a = new int[n][n];
        int[] visited = new int[n];
        int[] q = new int[20];
        System.out.println("Enter the adjacency matrix");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                a[i][j] = s.nextInt();
                visited[i] = 0;
            }
        }
        System.out.println("Enter the starting vertex");
        int source = s.nextInt();
        q[r] = source;
        visited[source] = 1;
        System.out.println("BFS order in which nodes are reached\n");
        while (true) {
            for (i = 0; i < n; i++) {
                if ((a[source][i] == 1 && visited[i] == 0)) {
                    q[++r] = i;
                    visited[i] = 1;
                }
            }
            System.out.println(" " + q[f++]);
            source = q[f];
            if (f > r)
                break;
        }
        if (n == f) {
            System.out.println("connected");
        } else {
            System.out.println("not connected");
        }
    }
}
