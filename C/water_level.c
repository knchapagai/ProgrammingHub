#include<stdio.h>
int main()
{
int a,i,b,d;
printf("The rate of water flow is 1 litre per second");
printf("\nNow ,enter the water level of the tank");
scanf("%d", &a);
for(i=0;i<=a;i++)
{
printf("\n%d", i);
}
printf("\nThe choices are \nTo stop the flow \nTo release water");
scanf("%d", &b);
switch(b)
{
case 1: printf("\nThe flow of water is stopped");
        break;
case 2: for(i=a;i>=0;i--)
        {
         d=i;
         printf("\n%d", d);
        }
}
return 0;
}
