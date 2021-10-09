//C# program to sort an array using merge sort

using System;

class Test
{
    static void Merge(int[] arr, int low, int mid, int high)
    {
        int[] tempArr = new int[arr.Length];

        int left1   =   0;
        int temp    =   0;

        int total = 0;
        int loop  = 0;

        left1 = (mid - 1);
        temp = low;
        total = (high - low + 1);

        while ((low <= left1) && (mid <= high))
        {
            if (arr[low] <= arr[mid])
                tempArr[temp++] = arr[low++];
            else
                tempArr[temp++] = arr[mid++];
        }
        while (low <= left1)
            tempArr[temp++] = arr[low++];
        while (mid <= high)
            tempArr[temp++] = arr[mid++];

        for (loop = 0; loop < total; loop++)
        {
            arr[high] = tempArr[high];
            high--;
        }

    }
    static void Sort(int[] arr, int low, int high)
    {
        int mid=0;

        if (high > low)
        {
            mid = (high + low) / 2;

            Sort(arr, low, mid);
            Sort(arr, (mid + 1), high);

            Merge(arr, low, (mid + 1), high);

        }
    }

    static void Main(string[] args)
    {
        int[] arr = { 32, 18, 27, 65, 12, 41, 22, 26, 44 };

        int length = 0;
        int loop   = 0;

        length = arr.Length;

        Sort(arr, 0, length - 1);

        Console.WriteLine("Sorted Array:");
        for (loop = 0; loop < arr.Length; loop++)
            Console.Write(arr[loop] + " ");
        Console.WriteLine();
    }
}
