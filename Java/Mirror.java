import java.io.*;

import java.util.*;

public class Mirror{

  static class Node{
    int data;
    Node left;
    Node right;
    
    // constructor 
    Node(int data){
      this.data = data;
      this.left = null;
      this.right = null;
    }

  }

  static Node root;
  static void create(){

    Scanner sc = new Scanner(System.in);

    Queue<Node> q = new LinkedList<>();
    int x;
    Node p,t;
    System.out.println("Enter the root");
    x = sc.nextInt();
    root = new Node(x);
    q.add(root);
    while(!q.isEmpty()){
     p = q.poll();
     System.out.println("Enter left node of "+p.data);
     x = sc.nextInt();
     if(x!=-1){
       t = new Node(x);
       p.left = t;
       q.add(t);
     }

     System.out.println("Enter right node of "+p.data);
     x = sc.nextInt();
     if(x!=-1){
       t = new Node(x);
       p.right = t;
       q.add(t);
     }
    }
  }

  static void Mirror(Node n){
    
    if(n==null){
      return;
    }
   

    Mirror(n.left);
    Mirror(n.right);
    swap(n);

  }

  static void swap(Node root){
    if(root == null){
      return;
    }
    Node temp = root.left;
    root.left = root.right;
    root.right = temp;
  }

  static void pre(Node n){
    if(n!=null){
      System.out.print(n.data+" ");
      pre(n.left);
      pre(n.right);
    }
  }
public static void main(String[] args) {
   create();
   pre(root); 
  }
}



