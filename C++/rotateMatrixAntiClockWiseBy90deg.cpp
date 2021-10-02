#include<bits/stdc++.h>
using namespace std;
void rotate90(int **mat, int n )
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            swap(mat[i][j],mat[j][i]);
        for(int i=0;i<n;i++)
        {
            int low=0,high=n-1;
            while(low<high)
            {
                swap(mat[low][i],mat[high][i]);
                low++;
                high--;
            }
        }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    int n=3;
    int *mat[n];
    for(int i=0;i<n;i++)
    {
         mat[i]=new int[n];
         for(int j=0;j<n;j++)
         {
             cin>>mat[i][j];
         }
    }
    rotate90(mat,n);
    return 0;
}