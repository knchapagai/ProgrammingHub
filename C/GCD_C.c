#include <stdio.h>  
#include <conio.h>  
int main()  
{  
    // declare the variables  
    int n1, n2, i, GCD_Num;  
    printf ( " Enter any two numbers: \n ");  
    scanf ( "%d %d", &n1, &n2);   
      
    // use for loop  
    for( i = 1; i <= n1 && i <= n2; ++i)  
    {  
        if (n1 % i ==0 && n2 % i == 0)  
            GCD_Num = i; /* if n1 and n2 is completely divisible by i, the divisible number will be the GCD_Num */  
    }  
    // print the GCD of two numbers  
    printf (" GCD of two numbers %d and %d is %d.", n1, n2, GCD_Num);  
    return 0;  
}  
