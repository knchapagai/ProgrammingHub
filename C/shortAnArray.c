#include <stdio.h>
#include <conio.h>

int main(){
int arr[] = {1,7,10,13,16,19};
int arr_size = sizeof(arr)/sizeof(int)-1;
int temp;


    for (int i = 0; i <= arr_size; i++)
    {
        for (int j = i + 1; j < arr_size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i <= arr_size; i++)
        printf("%5d", arr[i]);


return 0;
}