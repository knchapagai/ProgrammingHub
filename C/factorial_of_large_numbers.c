# include<stdio.h>
void main()
{
	int a[10000];\
	a[0]=1;
	printf("ENTER NUMBER\n");
	int n,i=1,c,x=0,size=1;
	scanf("%d",&n);
	{
		for(i;i<=n;i++)
		{
			c=0;
			x=0;
			while(x<size)
			{
				a[x]=a[x]*i;
				a[x]=a[x]+c;
				c=a[x]/10;
				a[x]=a[x]%10;
				x++;
			}
			while(c!=0)
			{
				a[size]=c%10;
				c/=10;
				size++;
								
			}
		}
		int j;
		for(j=size-1;j>=0;j--)
		{
			printf("%d",a[j]);
		}
	}
	
	
}
