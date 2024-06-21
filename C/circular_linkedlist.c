#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insertatstart(struct node **start,int ele){
	struct node *newnode,*ptr;
	//newnode creation
	newnode = (struct node*)(malloc(sizeof(struct node)));
	newnode->data = ele;
	//inserting newnode at correct position
	if (*start == NULL) {
		*start = newnode;
        newnode->next = *start;
	}
	else{
		ptr = *start;
        newnode->next = *start;
		while(ptr->next != *start) ptr = ptr->next;
        *start = newnode;
        ptr->next = *start;
	}
}

void insertatend(struct node **start,int ele){
	struct node *newnode,*ptr;
	//newnode creation
	newnode = (struct node*)(malloc(sizeof(struct node)));
	newnode->data = ele;
	//inserting newnode at correct position
	if (*start == NULL) {
		*start = newnode;
        newnode->next = *start;
	}
	else{
		ptr = *start;
		while(ptr->next != *start) ptr = ptr->next;
		ptr->next = newnode;
        newnode->next = *start;
	}
}

void display(struct node *start){
	struct node *ptr = start;
	if(start == NULL) printf("\nStart address : NULL");
	else{
		printf("\nStart address : %p -->",start);
		while(ptr->next != start){
			printf("| %d | %p | -->",ptr->data,ptr->next);
			ptr = ptr->next;
		}
		printf("| %d | %p (start address)|",ptr->data,ptr->next);
	}
}

void deletefromstart(struct node **start){
    struct node *ptr,*prev;
    if(*start == NULL) printf("Nothing to delete!");
    else{
        prev = *start;
        if((*start)->next == *start) *start = NULL;//only one node in list
        else{
            ptr = *start;
            while(ptr->next != *start) ptr = ptr->next;
            *start = (*start)->next;
            ptr->next = *start;
        }
        free(prev);
    }
}

void deletefromend(struct node **start){
    struct node *ptr,*prev;
    if(*start == NULL) printf("Nothing to delete!");
    else{
        prev = *start;
        ptr = *start;
        if((*start)->next == *start) *start = NULL;//only one node in list
        else{
            while(ptr->next != *start) {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = *start;
        }
        free(ptr);
    }
}

int search(struct node *start,int ele){
    struct node *ptr = start;
    if(start == NULL) {
        printf("\nCan't search in empty circular list\n");
        return 0;
    }
    else{
        do{
            if(ptr->data == ele) return 1;
            ptr = ptr->next;
        }while(ptr != start);
        return 0;
    }
}

int main(){
	int ch,ele;
	struct node *start = NULL;
	while(1){
		printf("\n0. Exit\n1. Insert at start\n2. Insert at end\n3. Display\n4. Delete from start\n5. Delete from end\n6. Search\nEnter your choice : ");
		scanf("%d",&ch);
		if(ch==0) break;
		else if(ch==1 || ch==2){
			printf("\nEnter element : ");
			scanf("%d",&ele);
			(ch==1)?insertatstart(&start,ele) : insertatend(&start,ele);
		}
		else if(ch==3) display(start);
        else if(ch==4) deletefromstart(&start);
        else if(ch==5) deletefromend(&start);
        else if(ch==6){
            printf("\nEnter element to search : ");
            scanf("%d",&ele);
            if(search(start,ele)) printf("\n%d found in circular list.\n",ele);
            else printf("\nSorry!!! number not found.\n");
        }
        else printf("\nWrong choice!!!\n");
	}
	return 0;
}
