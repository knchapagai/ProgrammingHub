//C# program to sort an array using quick sort

using System;

class Sort
{
    private int[] intArray;
    
    //Initialize array
    public Sort(int []arr)
    {
        intArray = new int[arr.Length];
        intArray = arr;

    }
    public void QuickSort(int low, int high)
    {
        int pivot    =0;
        int left     =0;
        int right    =0;

        left = low;
        right = high;
        pivot = intArray[low];

        while (low < high)
        {
            while ((intArray[high] >= pivot) && (low < high))
            {
                high--;
            }

            if (low != high)
            {
                intArray[low] = intArray[high];
                low++;
            }

            while ((intArray[low] <= pivot) && (low < high))
            {
                low++;
            }

            if (low != high)
            {
                intArray[high] = intArray[low];
                high--;
            }
        }

        intArray[low] = pivot;
        pivot = low;
        low = left;
        high = right;

        if (low < pivot)
        {
            QuickSort(low, pivot - 1);
        }

        if (high > pivot)
        {
            QuickSort(pivot + 1, high);
        }
    }

    public static void Main()
    {
        int[] arr = { 12,21,13,32,34,43,77,42 };
     
        Sort sort = new Sort(arr);

        int length  = 0;
        int loop    = 0;

        length = arr.Length;

        sort.QuickSort(0,length-1);

        Console.WriteLine("Sorted array:");
        for (loop = 0; loop < length; loop++)
        {
            Console.Write(sort.intArray[loop]+" ");
        }
        Console.WriteLine();
    }
}
