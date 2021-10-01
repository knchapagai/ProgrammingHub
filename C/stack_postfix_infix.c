#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char data;
	struct node * next;
} node;
typedef struct stack{
	node * data;
	struct stack * next;
}stack;
node * create(char a);
stack * push(node *a);
node * pop();
int isOperator(char a);
node * insert_start(node * head,char a);
void insert_end(node * head,char a);
void display(node * head);
void joinnode(node * a,node * b);
stack * createforstack(node * a);
node * ans=NULL;
stack * head=NULL;
int main(){
	char a[101];
		printf("Enter your postfix expression\nNOTE: Please dont give any space in between characters\n");

	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++){
		if(isOperator(a[i])){
			node * second=pop();
			node * first=pop();
			insert_end(first,a[i]);
			joinnode(first,second);
			ans=first;
			ans=insert_start(ans,'(');

			insert_end(ans,')');
			head=push(ans);
		}
		else{node * newd=(create(a[i]));
		 head=push(newd);
	}
}

display(ans);
	return 0;
}
node * create(char a){
	node * newd=(node *)malloc(sizeof(node));
	newd->data=a;
	newd->next=NULL;
	return newd;
}
stack * createforstack(node * a){
	stack * newd=(stack*)malloc(sizeof(stack));
	newd->data=a;
	return newd;
}
stack * push(node * a){
	stack * newd=createforstack(a);
	newd->next=head;
	return newd;
}
node * pop(){
	node * val=head->data;
	stack * garbage=head;
	head=head->next;
	free(garbage);
	return val;
}
int isOperator(char a){
	if(a=='+' ||a=='-' ||a=='*' ||a=='/' ||a=='^' || a=='%') return 1;
	else return 0;
}
node * insert_start(node * head,char a){
	node * newd=create(a);
	newd->next=head;
	return newd;
}
void insert_end(node * head,char a){
	while(head->next!=NULL) head=head->next;
	head->next=create(a);
	head->next->next=NULL;
}
void display(node * head){
	if(head==NULL) return ;
	printf("%c",head->data);
	display(head->next);
}
void joinnode(node * a,node * b){
	while(a->next!=NULL) a=a->next;
	a->next=b;
	
}