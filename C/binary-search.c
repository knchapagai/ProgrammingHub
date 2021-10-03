#include<stdio.h>
int main()
{
    int a[200],n,i;
    printf("\n Enter no. of elements : ");
    scanf("%d",&n);
    printf("\n Enter array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int temp,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\n array in asc. order is : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    int l=0,h=n-1,m=(l+h)/2;   
    int e,flag;
    printf("\n Enter element to search : ");
    scanf("%d",&e);
    while(l<=h)
    {
        if(e==a[m])
        {
            flag=1;
            break;
        }
        else if(e>a[m])
        {
            l=m+1;
            m=(l+h)/2;
        }
        else if(e<a[m])
        {
            h=m-1;
            m=(l+h)/2;
        }
    }
    if(flag==1)
    {
        printf("\n Element if found.");
        printf("\n Position of element in sorted array is %d.",m+1);
    }
    else
        printf("\n element is not in array.");

        printf("\n);
    return 0;
}
