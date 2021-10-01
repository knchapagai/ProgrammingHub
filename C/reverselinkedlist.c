// Apsara Budathoki | Reverse LinkedList in C
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *first=NULL;

void create(int A[],int n){
    struct Node *t,*last;
     int i;
     first=(struct Node*)malloc(sizeof(struct Node));
     first->data=A[0];
     first->next=NULL;
     last=first;
     for(i=1;i<n;i++)
     {
     t=(struct Node*)malloc(sizeof(struct Node));
     t->data=A[i];
     t->next=NULL;
     last->next=t;
     last=t;
}
}
int count (struct Node *p)
{
    int c=0;
    while(p!=0)
    {
        c++;
        p=p->next;
    }
    return c;
}

int  Display(struct Node *p)
{
    while(p)
    {
    printf("%d\t",p->data);
    p=p->next;
}
}

int Reverse(struct Node *p)
{
    
    int i=0,*A;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q=NULL, *temp=NULL;
    while(p!=0)
    {
        temp=q;
        q=p;
        p=p->next;
        q->next=temp;
    }

    first=q;
}
void Reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
        
    }
    else
    first=q;
}

int main(){
    struct Node *p;
    int A[]={2,3,45,65};
    create(A,4);
    Reverse3(NULL,first) ;
    Display(first);
    return 0;
}
