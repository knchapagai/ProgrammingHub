#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
clrscr();
int i,n,a[100],b[100],c[100],p=0,q=0,Y;
char m;
printf("Enter number of elements : ");
scanf("%d",&n);
printf("\nEnter %d elements = \n",n);
for(i=0;i<n;i++)
 {
 scanf("\n%d",&a[i]);
 }
for(i=0;i<n;i++)
 {
  b[p]=a[i];
  p++;
 }
printf("\nThe original array you entered is -\n");
for(i=0;i<n;i++)
 {
 printf("\n%d",a[i]);
 }
printf("\nThe above array has been copied into another array.\n");
printf("\nCopied array is -\n");
for(p=0;p<n;p++)
 {
 printf("\n%d",b[p]);
 }
printf("\nWould you like to edit your first array? Y/N \n");
scanf("%s",&m);
if(m=='Y')
 {
  printf("\nEnter new elements -\n");
  free(a);
  for(i=0;i<n;i++)
   {
   scanf("%d",&a[i]);
   }
  printf("\nEdited array is as follows -\n");
  for(i=0;i<n;i++)
   {
   printf("\n%d",a[i]);
   }
  printf("\nThank you for the details.");
 }
else
 {
 printf("\nThank you for the details.");
 }
getch();
}
