#include <stdio.h>
int main()
{
    int num1, num2, num3, count;
    printf("Enter the Starting two Numbers: ");
    scanf("%d%d", &num1, &num2);
    printf("Enter the Number upto Till you want the series: ");
    scanf("%d", &count);
    printf("The fabonacci series is : %d,%d,", num1, num2);
    if (count > 2)
    {
        int i = 0;
        for (i = 3; i <= count; i++)
        {
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
            printf("%d", num3);
            if (i == count)
            {
                printf(" ");
            }
            else
            {
                printf(",");
            }
        }
    }
    return 0;
}