#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head;
void insertAtHead(int x){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    head=temp;
}

void insertAtNode(int x, int n){
    struct node* p = head;
    struct node* pnext= head->next;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    for(int i=1; i<n-1; i++){
        p=p->next;
        pnext=pnext->next;
    }
    temp->data=x;
    p->next= temp;
    temp->next=pnext;
}

void insertAtLast(int x){
    struct node* p = head;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=x;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = temp;
    temp->next = NULL;
}

void deleteHead(){
    struct node* p = head;
    head = head->next;
    free(p);
    
}

void deleteNode(int n){
        struct node* p=head;
        struct node* pnext = head->next;
        for(int i=0; i<n-1; i++){
            p = p->next;
            pnext= pnext->next;
        }
        p->next = pnext->next;
        free(pnext);
        
    }

struct node* deleteAtLast(){
    struct node* temp = head;
    struct node* tempn = head->next;
    while(temp->next != NULL){
        temp=temp->next;
        tempn=tempn->next;
    }
    temp->next = NULL;
    free(tempn);
}

void display(){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d   ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    display();
    printf("\n");
    insertAtNode(11, 2);
    insertAtNode(11, 3);
    display();
    printf("\n");
    insertAtLast(5);
    insertAtLast(6);
    display();
    printf("\n");
     deleteHead();
    deleteHead();
    display();
    printf("\n");
    deleteNode(2);
    display();
    printf("\n");
    deleteAtLast();
    deleteAtLast();
    display();
    printf("\n");

    return 0;

}