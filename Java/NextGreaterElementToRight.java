import java.util.*;
public class NextGreaterElementToRight{

  static int[] solve(int a[]){
    
    Stack<Integer> st = new Stack<>();
    int nge[] = new int[a.length];

    nge[a.length-1] = -1;
    st.push(a[a.length-1]);


    for(int i = a.length-2; i >=0; i--){

      while(st.size() > 0 && a[i] >= st.peek()){
       st.pop(); 
      }
      if(st.size()> 0){
        nge[i] = st.peek();
      }
      else{
        nge[i] = -1;
      }
      st.push(a[i]);
    }
   return nge; 

  } 
  
  public static void main(String[] args) {
    
    int a[] = {4,3};

    int b[] = solve(a);
    for(int i =0; i <a.length;i++){
      System.out.println(b[i]);
    }
    }
}
