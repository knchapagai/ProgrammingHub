#include<stdio.h>
#define max 5
char ob[5]={'D','P','G','S','B'};
int p[]={5000,4000,4500,6250,5000};
int w[]={10,10,15,25,50};
int p_w[max];int c=15;
void swap(int*p,int*q)
{
	int t=*p;
	*p=*q;
	*q=t;
}
void main()
{
	int i=0;
	for(i;i<max;i++)
		p_w[i]=p[i]/w[i];
    for(i=0;i<max-1;i++)
    {
    	int j=0;
    	for(j;j<max-i-1;j++)
    	{
    		if(p_w[j]<p_w[j+1])
    		{
    			swap(&p_w[j],&p_w[j+1]);
    			swap(&p[j],&p[j+1]);
    			swap(&w[j],&w[j+1]);
    			char ch=ob[j];
    			ob[j]=ob[j+1];
    			ob[j=i]=ob[j];
			}
		}
	}
	int o_p=0;
	for(i=0;c>0;i++)
	{
		if(w[i]<=c)
		{
			printf("\n 1 of %c",ob[i]);
			o_p=o_p+p[i];
			c=c-w[i];
		}
		else
		{
			o_p=o_p+(c)*p_w[i];
			printf("\n %d/%d of %c",c,w[i],ob[i]);
			c=0;
		}
	}
	printf("\n Optimized Profit= %d",o_p);
}
