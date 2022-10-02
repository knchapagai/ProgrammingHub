import java.util.Scanner;

public class RupeeConvertionToDollar{
    public static void main(String[] arr){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter a Rupee value to convert it in Dollar value");
        int rupee = scan.nextInt();

        System.out.println("corresponding Doller value :"+rupee*0.0136824549);
    }
}
