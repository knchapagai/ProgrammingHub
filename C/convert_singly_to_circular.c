#include <stdio.h>

#include <stdlib.h>

struct node

{

    int num;

    struct node *next;
};

void create(struct node **);

void tocircular(struct node **);

void release(struct node **);

void display(struct node *);

int main()

{

    struct node *p = NULL;

    int result, count;

    printf("Enter data into  list\n");

    create(&p);

    tocircular(&p);

    printf("Circular list is generated\n");

    display(p);

    release(&p);

    return 0;
}

void tocircular(struct node **p)

{

    struct node *rear;

    rear = *p;

    while (rear->next != NULL)

    {

        rear = rear->next;
    }

    rear->next = *p;

}

void create(struct node **head)

{

    int c, ch;

    struct node *temp;

    do

    {

        printf("Enter number: ");

        scanf("%d", &c);

        temp = (struct node *)malloc(sizeof(struct node));

        temp->num = c;

        temp->next = *head;

        *head = temp;

        printf("Do you wish to continue [1/0]: ");

        scanf("%d", &ch);

    } while (ch != 0);

    printf("\n");
}

void display(struct node *head)

{

    struct node *temp = head;

    printf("Displaying the list elements\n");

    printf("%d\t", temp->num);

    temp = temp->next;

    while (head != temp)

    {

        printf("%d\t", temp->num);

        temp = temp->next;
    }

    printf("and back to %d\t%d ..\n", temp->num, temp->next->num);
}

void release(struct node **head)

{

    struct node *temp = *head;

    temp = temp->next;

    (*head)->next = NULL;

    (*head) = temp->next;

    while ((*head) != NULL)

    {

        free(temp);

        temp = *head;

        (*head) = (*head)->next;
    }
}
