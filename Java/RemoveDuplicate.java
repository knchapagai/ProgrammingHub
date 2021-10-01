public class RemoveDuplicate{
  
  static Node first;
  static class Node{

    int data;
    Node next;

    Node(int data){
      this.data = data;
      this.next = next;

    }

  }

  static void create(int a[]){
    Node last,t;
    first = new Node(a[0]);

    last = first;

    for(int i = 1; i <a.length; i++){
      t = new Node(a[i]);

      last.next = t;
      last = t;
    }
  }

   static void display(Node n){
    if(n!=null){
      System.out.print(n.data+" ");
      display(n.next);
    }
  }

  static void remove_duplicate(Node n){
    
    Node q = n.next;
    while(q!=null){
      if(n.data!=q.data){
        n = q;
        q = q.next;
      }
      else{
        n.next = q.next;

        q = n.next;
      }
    }
  }

  
  

  public static void main(String[] args) {
    int a[] = {10,20,20,20,50};

    create(a);

    remove_duplicate(first);
    display(first);
  }
}

