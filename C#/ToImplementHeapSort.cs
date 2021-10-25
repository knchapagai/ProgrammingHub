//C# program to implement the Heap Sort

using System;

class Sort
{
    private void Adjust(int []arr,int i, int n)
    {
        int temp=0;
        int loop=0;

        temp = arr[i];
        loop = 2 * i;
        while (loop <= n)
        {
            if (loop < n && arr[loop] < arr[loop + 1])
                loop++;
            if (temp >= arr[loop])
                break;
            arr[loop / 2] = arr[loop];
            loop = loop*2;
        }
        arr[loop / 2] = temp;
    }
    
    public void HeapSort(int []arr)
    {
        int loop=0;
        int temp=0;
        for (loop = 5; loop >= 0; loop--)
        {
            Adjust(arr, loop, 9);
        }
        for (loop = 8; loop >= 0; loop--)
        {
            temp = arr[loop + 1];
            arr[loop + 1] = arr[0];
            arr[0] = temp;
            Adjust(arr, 0, loop);
        }
    }
    
    public static void Main()
    {
        int loop = 0;
        int[] arr = { 22, 51, 21, 10, 36, 59, 33, 67, 64, 18 };
        
        Sort H = new Sort();

        H.HeapSort(arr);

        Console.WriteLine("Sorted Array: ");
        for (loop = 0; loop < arr.Length; loop++)
            Console.Write(arr[loop] + " ");

        Console.WriteLine();
    }
}
