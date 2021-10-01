#include <stdio.h>
#define N 50
int stack[N];
int top = -1;

void push(int x)
{
    if (top == N - 1)
    {
        printf("Stack Overflow\n");
    }

    else
    {
        stack[++top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int ele = stack[top--];
        printf("The popped element is %d\n", ele);
    }
}

void display()
{
    int i = 0;
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice=1, item;
    while(choice)
    {
        printf("Type 1 for push, 2 for pop, 3 for display, 0 to exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to be pushed\n");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            default:
                if (choice != 0)
                {
                    printf("Invalid operation\n");
                }
                break;
        }
    }

}