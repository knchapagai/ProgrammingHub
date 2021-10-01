#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node * next;
} node;
node * head=NULL;
int isOperator(char a);
int pow(int a,int b);
node * create(int a);
node * push(int a);
int pop();
int main(){
	char a[101];
	printf("Enter your postfix expression\nNOTE: Please dont give any space in between characters\n");
	scanf("%s",a);
	int ans;
	for(int i=0;a[i]!='\0';i++){
		if(isOperator(a[i])){
			int second=pop();
			int first=pop();
			if(a[i]=='+') ans=first+second;
			else if(a[i]=='-') ans=first-second;
			else if(a[i]=='*') ans=first*second;
			else if(a[i]=='/') ans=first/second;
			else if(a[i]=='%') ans=first%second;
			else if(a[i]=='^') ans=pow(first,second);
			head=push(ans);

		}
		else head=push(a[i]-'0');
		
	}
printf("%d",ans);

	return 0;
}
int isOperator(char a){
	if(a=='+' ||a=='-' ||a=='*' ||a=='/' ||a=='^' || a=='%') return 1;
	else return 0;
}
int pow(int a,int b){
	int ans=1;
	while(b--) ans*=a;
	return ans;
}
node * create(int a){
	node * newd=(node *)malloc(sizeof(node));
	newd->data=a;
	return newd;
}
node * push(int a){
	node * newd=create(a);
	newd->next=head;
	return newd;
}
int pop(){
	int val=head->data;
	node * garbage=head;
	head=head->next;
	free(garbage);
	return val;
}