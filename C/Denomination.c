#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long int amount;
    printf("Enter the amount: ");
    scanf("%lld", &amount);
    int count2000 = 0, count500 = 0, count100 = 0, count50 = 0, count20 = 0;

    if (amount >= 2000)
    {
        count2000 = amount / 2000;
        printf("required no of 2000 notes %d\n", count2000);
    }
    count2000 = count2000 * 2000;
    amount -= count2000;

    if (amount >= 500)
    {
        count500 = amount / 500;
    }
    printf("required no of 500 notes %d\n", count500);

    count500 *= 500;
    amount -= count500;

    if (amount >= 100)
    {
        count100 = amount / 100;
    }
    printf("required no of 100 notes %d\n", count100);
    count100 *= 100;
    amount -= count100;

    if (amount >= 50)
    {
        count50 = amount / 50;
    }
    printf("required no of 50 notes %d\n", count50);
    count50 *= 50;
    amount -= count50;

    if (amount >= 20)
    {
        count20 = amount / 20;
    }
    printf("required no of 20 notes %d\n", count20);
    count20 *= 20;
    amount -= count20;
}