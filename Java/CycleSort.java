import java.util.*;
public class MissingNumber {
	public static void main(String[] args)
	{
		int[] arr = { 3, 2, 4, 5, 1 };
		int n = arr.length;
		System.out.println("Before sort :");
		System.out.println(Arrays.toString(arr));
		CycleSort(arr, n);
		
	}

	static void CycleSort(int[] arr, int n)
	{
		int i = 0;
		while (i < n) {
		
			int correctpos = arr[i] - 1;
			if (arr[i] < n && arr[i] != arr[correctpos]) {
				
				swap(arr, i, correctpos);
			}
			else {
				i++;
			}
		}
			System.out.println("After sort : ");
			System.out.print(Arrays.toString(arr));
		
		
	}

	static void swap(int[] arr, int i, int correctpos)
	{
	
		int temp = arr[i];
		arr[i] = arr[correctpos];
		arr[correctpos] = temp;
	}
}

