import java.io.*;

import java.util.*;

public class Hollowhalfdiamond{

  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    int sp = n+1;

    for(int i = 1; i <=n; i++){
      
      for(int j = 1;j <=1; j++){

        System.out.println("*\t");
      }

      for(int k = 1; k <=sp; k++){
          System.out.print("\t");
      }
      sp-=2;

      for(int l = 1; l <=i; l++){
        System.out.print("*\t");
      }

     System.out.println(); 
    }
  }
}
