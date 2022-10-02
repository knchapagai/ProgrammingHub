/*
Implementation of Stack and Queue Using Linked list

Implement the abstract data type of QUEUE and STACK by linear linked list at least below 
set of operations:

For QUEUE: enqueue, dequeue [MARKS: 15]

For STACK: POP, PUSH    [MARKS 10]

Pre-condition:

1. The programme should be menu driven.

2. Master Menu: STACK AND QUEUE. And Inside the specific menu submenu should be there.

Approach:

1. First create the linear link list Abstract Data Type (Create, Insert, Delete Linked list)

2. Use the linked list to implement Stack and Queue.

Creator : Arnab Chakraborty
Github : https://github.com/ArnabC27
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top, *top1, *temp, *front, *front1, *rear;


void createStack()
{
    top = NULL;
}

struct Queue* createQueue()
{
    front = rear = NULL;
}

void push(int d)
{
    if(top == NULL)
    {
        top = (struct Node*)malloc(sizeof(struct Node));
        top->next = NULL;
        top->data = d;
    }
    else
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->next = top;
        temp->data = d;
        top = temp;
    }
}

void pop()
{
    top1 = top;

    if(top == NULL)
    {
        printf("\nStack Underflow!!!\n");
        return;
    }
    else
    {
        top1 = top->next;
    }
    printf("Element Popped : %d\n", top->data);
    free(top);
    top = top1;
}

void printStack()
{
    top1 = top;

    if(top1 == NULL)
    {
        printf("\nStack is Empty!!!\n");
        return;
    }

    printf("Stack Status :\n");
    printf("TOP\n |\n");
    while(top1 != NULL)
    {
        printf(" %d\n", top1->data);
        top1 = top1->next;
    }
}

void executeStack()
{
    printf("\n-----STACK IMPLEMENTATION USING LINKED LIST-----\n");
    int d, ch, cont = 1;
    createStack();

    while(cont == 1)
    {
        printf("Stack Operations that can be performed here : \n");
        printf("1. Push an element in the Stack.\n");
        printf("2. Pop the element at top of the Stack.\n");
        printf("3. Display Stack Status.\n");
        printf("Enter Your Choice (1-3) : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 :
                printf("Enter an Integer you want to Push : ");
                scanf("%d", &d);
                push(d);
                break;
            case 2 :
                pop();
                break;
            case 3 :
                printStack();
                break;
            default :
                printf("\nSorry!!! Invalid Choice!!!\n");
        }

        printf("Do you want to Continue? (1-YES/ 0-NO) : ");
        scanf("%d", &cont);
    }
}

void enqueue(int d)
{
    if(rear == NULL)
    {
        rear = (struct Node*)malloc(sizeof(struct Node));
        rear->next = NULL;
        rear->data = d;
        front = rear;
    }
    else
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        rear->next = temp;
        temp->data = d;
        temp->next = NULL;
        rear = temp;
    }
}

void dequeue()
{
    front1 = front;

    if(front1 == NULL)
    {
        printf("\nQueue Underflow!!!\n");
        return;
    }
    else
    {
        if(front1->next != NULL)
        {
            front1 = front1->next;
            printf("Dequeued Element : %d\n", front->data);
            free(front);
            front = front1;
        }
        else
        {
            printf("Dequeued Element : %d\n", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
    }
}

void printQueue()
{
    printf("\nQueue Status :\n");
    front1 = front;
    if((front1 == NULL) && (rear == NULL))
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("FRONT -> ");
    while(front1 != rear)
    {
        printf("%d ", front1->data);
        front1 = front1->next;
    }
    if(front1 == rear)
        printf("%d <- REAR\n", front1->data);
}

void executeQueue()
{
    printf("\n-----QUEUE IMPLEMENTATION USING LINKED LIST-----\n");
    int d, ch, cont = 1;
    createQueue();

    while(cont == 1)
    {
        printf("Queue Operations that can be performed here : \n");
        printf("1. Enqueue an element in the Stack.\n");
        printf("2. Dequeue the element at top of the Stack.\n");
        printf("3. Display Queue Status.\n");
        printf("Enter Your Choice (1-3) : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 :
                printf("Enter an Integer you want to Enqueue : ");
                scanf("%d", &d);
                enqueue(d);
                break;
            case 2 :
                dequeue();
                break;
            case 3 :
                printQueue();
                break;
            default :
                printf("\nSorry!!! Invalid Choice!!!\n");
        }

        printf("Do you want to Continue? (1-YES/ 0-NO) : ");
        scanf("%d", &cont);
    }
}

int main()
{
    printf("\n-----STACK AND QUEUE IMPLEMENTATION USING LINKED LIST-----\n");
    char ch;
    printf("Which Data Structure do you want to work on ?");
    printf("\nEnter S for Stack and Q for Queue : ");
    scanf("%c", &ch);

    switch(ch)
    {
        case 'S' :
            executeStack();
            break;
        case 'Q' :
            executeQueue();
            break;
        default :
            printf("\nSorry!!! Invalid Choice!!!\n");
    }
    return 0;
}