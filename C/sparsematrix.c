#include <stdio.h>
#include <stdlib.h>
struct node{
    int row, col;
    float val;
    struct node *link;
}*t1,*t2,*temp,*new,*prod;

void new_node(int row, int col, float val){
    struct node *check=prod;
    if(prod) check=check->link;
    while(check){
        if(check->row == row && check->col == col){
            check->val += val;
            return;
        }
        check=check->link;
    }
    new=malloc(sizeof(struct node));
    new->row=row; new->col=col;
    new->val=val; new->link=NULL;
    temp->link=new; temp=new;
}

void display(struct node *ptr){
    temp=ptr;
    while(temp){
        if(temp->val!=0)
            printf("%d %d %.2f\n", temp->row, temp->col, temp->val);
        temp=temp->link;
    }
}
void create(struct node *ptr){
    int r,c; float v; temp=ptr;
    printf("Enter Row, Column, Value for :\n");
    for(int i=0;i<ptr->val;i++){
        check:
        printf("Input %d : ",i+1);
        scanf("%d%d%f",&r,&c,&v);
        if(r>ptr->row || c>ptr->col || r<1 || c<1){
            printf("Row or Column Exceeded\n");
            goto check;
        }
        new_node(r,c,v);
    }
    printf("\nINPUT :\n");
    display(ptr);
}

void mul(struct node *ptr1,struct node *ptr2){
    if(ptr1->col!=ptr2->row){
        printf("Product Not possible\n");
        return;
    }
    prod=malloc(sizeof(struct node));
    prod->row=ptr1->row; prod->col=ptr2->col;
    prod->val=0; prod->link=NULL;
    t1=ptr1->link; temp=prod;
    while(t1!=NULL){
        t2=ptr2->link;
        while(t2!=NULL){
            if(t1->col==t2->row){
                new_node(t1->row,t2->col,(t1->val)*(t2->val));
                prod->val++;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }
    printf("\nProduct :\n");
    display(prod);
}

int main(){
    struct node *a, *b, *temp;
    printf("\nMatrix 1 :\n");
    printf("Enter total row, column & non-zero elements : ");
    a=malloc(sizeof(struct node));
    scanf("%d%d%f",&a->row,&a->col,&a->val);
    a->link=NULL;
    create(a);
    printf("\nMatrix 2 :\n");
    printf("Enter total row, column & non-zero elements : ");
    b=malloc(sizeof(struct node));
    scanf("%d%d%f",&b->row,&b->col,&b->val);
    b->link=NULL;
    create(b);
    mul(a,b);
    return 0;
}