#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next= NULL;
    
    Node(int data){
        this -> data = data;
    }
};

Node* reverse_better(Node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }
    Node* smallans = reverse_better(head->next);
    Node* tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallans;
}

Node* reverse(Node* head){
    if(head->next == NULL){
        return head;
    }
    Node* Ans= reverse(head->next);
    Node* temp=Ans;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return Ans;
}

Node* insert(){
    int data;
    Node* head=NULL;
    char a='y';
    while(a == 'y'){
        cin>>data;
        Node* n= new Node(data);
        if(head==NULL){
            head=n;
        }
        else{
            Node* temp=head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=n;
        }
        cout<<"Enter y or n : ";
        cin>>a;
    }
    return head;
}

void Display(Node* head){
    Node* t=head;
    while(t !=NULL){
        cout <<t->data<< " ,";
        t=t->next;
    }
}
int main(){
    Node* head=insert();
    Display(head);
    cout<<endl;
    Node* reverseHead=reverse_better(head);
    Display(reverseHead);
}