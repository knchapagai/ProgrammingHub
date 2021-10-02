/*
Program to sort the array using merge sort

code by iamkakashi
*/
#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r){
    int n=max(a[m],a[r])+1;
    int i=l,j=m+1,k=l;
    while(i<=m && j<=r && k<=r){
        int e=a[i]%n;
        int e1=a[j]%n;
        if(e<=e1){
            a[k]+=e*n;
            k++;
            i++;
        }
        else{
            a[k]+=e1*n;
            k++;
            j++;
        }
    }
    while(i<=m){
        int e=a[i]%n;
        a[k]+=e*n;
        k++;
        i++;
    }
    while(j<=r){
        int e1=a[j]%n;
        a[k]+=e1*n;
        k++;
        j++;
    }
    for(int i=l;i<=r;i++){
        a[i]=a[i]/n;
    }
}
void mergeSort(int a[], int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{
    int n,i;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n+1];
    cout<<"Enter elements: ";
    for(i=0;i<n;i++){
      cin>>arr[i];
    }
    mergeSort(arr, 0, n-1);
    cout<<"Sorted array is: ";
    printArray(arr, n);

    return 0;
} 