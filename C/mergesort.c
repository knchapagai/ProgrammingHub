#include<stdio.h>
void merge(int ar[],int s,int mid ,int l)
{
    int i=s,j=mid+1,index=s,size=l-s+1;
    int temp[50];
    while(i<=mid&&j<=l)
    {
        if(ar[i]<=ar[j])
        {
            temp[index]=ar[i];
            i++;
            index++;
        }
        else
        {
            temp[index]=ar[j];
            j++;
            index++;
        }
    }
    while(i<=mid)
    {
        temp[index]=ar[i];
        i++;
        index++;
    }
    
    while(j<=l)
    {
        temp[index]=ar[j];
        j++;
        index++;
    }
    for(int k=0;k<size;k++)
    {
        ar[k]=temp[k];
    }
}
void mergesort(int ar[],int s,int l)
{
    int mid;
    if (s<l)
    {
        mid=(s+l)/2;
        mergesort(ar,s,mid);
        mergesort(ar,mid+1,l);
        merge(ar,s,mid,l);
    }
}
int main()
{
    int ar[50],size;
    printf("Enter the array size:\n");
    scanf("%d",&size);
    printf("Enter the array:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&ar[i]);
    }
    mergesort(ar,0,size-1);
    printf("The new array is :\n");
    for(int i=0;i<size;i++)
    {
        printf("%d \n",ar[i]);
    }
}