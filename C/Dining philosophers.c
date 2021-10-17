#include <stdio.h>

solution(int cs[],int i,int n)
{
                cs[i]=wait(cs[i]);
                cs[(i+1)%n]=wait(cs[(i+1)%n]);
}
void main(){
    int i,n,j,c=1,k=0,x;
    int cs[100];
    printf("Enter number of philospohers: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        cs[i]=1;//available
    }
    if(n%2==0)
    {
        printf("\n\tSolution 1 : ");
        for(i=0;i<n;i++){
            if(cs[i]==1 && cs[(i+1)%n]==1){
		        solution(cs,i,n);
                printf("\n\t\tPhilospher %d is eating",i);
            }
            else
            {
                    printf("\n\t\tPhilospher %d is thinking",i);
            }
     
        for(i=0;i<n;i++){
            if(cs[i]==0)
                cs[i]=signal(cs[i]);
        }
        }
        printf("\n\tSolution 2 : ");
        for(i=0;i<n;i++){
            if(cs[i]==1 && cs[(i+1)%n]==1){
                solution(cs,i,n);
                printf("\n\t\tPhilospher %d is thinking",i);
            }
            else
            {
                    printf("\n\t\tPhilospher %d is eating",i);
            }
        }
    }
    else{
        
        for(i=1;i<=n;i++){
            printf("\n\tSolution %d is: ",i);
            for(j=k;c<=n;j=(j+1)%n){
                if(cs[j]==1 && cs[(j+1)%n]==1){
                solution(cs,j,n);
                printf("\n\t\tPhilospher %d is eating",j);
                }
                else
                {
                    printf("\n\t\tPhilospher %d is thinking",j);
                }
                c++;
            }
            k++;
            c=0;
            for(x=0;x<n;x++){
                if(cs[x]==0)
                    cs[x]=signal(cs[x]);
            }
        }
    }
    printf("\nExit");
}

//wait function
int wait(int s){
    s--;
    return s;
}
//signal function
int signal(int s){
    s++;
    return s;
}

