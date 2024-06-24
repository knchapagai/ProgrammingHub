import java.util.Scanner;

public class SelectionSort {

	public static void main(String[] args) {
		{
		    
		        int i,j,n,temp;
		        Scanner sc =new Scanner(System.in);
		        System.out.println("Enter the value of n: ");
		        n=sc.nextInt();
		        int a[]=new int[n];
		        System.out.println("Enter the elements: ");
		        for(i=0;i<n;i++)
		        {
		            a[i]=sc.nextInt();
		        }
		        for(i=0;i<n-1;i++)
		        {
		            int min=i;
		            for(j=i+1;j<n;j++)
		            {
		                if(a[j]<a[min])
		                min=j;

		            }
		            if(min!=j)
		            {
		                temp=a[min];
		                a[min]=a[i];
		                a[i]=temp;
		            }
		        }
		       
		        

		    }
		}
	}


