/* 
*   Program checks if Matrix is symmetric or not and finds the sum of left and right diagonals
*	  Accept size M
* 	Input values in array
*  	Display original matrix
* 	Check if marix is symmetric
* 	Add left diagonal elements and right diagonal elements
* 	Display if the matrix is symmetric or not
* 	Print sum of left and right diagonal elements
*/


import java.util.*;
class SymmetricMatrix
{
    void main()
    {
        int M; 
        int arr[][];
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of rows and coloumn");
        M=sc.nextInt();
        arr=new int[M][M];
        if( M<=0)
        { 
           System.out.println("Enter positive number");
        }
        else
        {
            int lsum=0; int rsum=0;
            for(int i=0; i<M; i++)
            {
                for(int j=0; j<M; j++)
                {
                    System.out.println("enter integer");
                    arr[i][j]=sc.nextInt();
                }
            }

            System.out.println("Original Matrix");
            for(int i=0; i<M; i++)
            {//Printing original matrix
                for(int j=0; j<M; j++)
                {
                    System.out.print(arr[i][j]+" ");
                }
                System.out.println();
            }

            int c=0;
            for(int i=0; i<M; i++)
            {
                for(int j=0; j<M; j++)
                {
                    if(arr[i][j]!=arr[j][i])
                        c++;
                    if(i==j)
                        lsum +=arr[i][j];
                    if((i+j)==(M-1))
                        rsum += arr[i][j];
                }
            }
            if(c==0)
                System.out.println("THE GIVEN MATRIX IS SYMMETRIC");
            else
                System.out.println("THE GIVEN MATRIX IS NOT SYMMETRIC");
            System.out.println("The sum of the left diagonal = "+lsum);
            System.out.println("The sum of the right diagonal = "+ rsum);
        }
    }
}
