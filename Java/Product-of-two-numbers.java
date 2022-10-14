import java.util.Scanner;

public class MultiplyExample3 {

       public static void main(String[] args) {

           Scanner scanner = new Scanner(System.in);
           System.out.print("Enter first number = ");
           double myDouble1 = scanner.nextDouble();
           System.out.print("Enter second number =  ");
           double myDouble2 = scanner.nextDouble();
           scanner.close();

           double result = myDouble1*myDouble2;

           // Displaying the multiplication result
           System.out.println(myDouble1 + "*" + myDouble2 + " = " + result);
       }
   }
