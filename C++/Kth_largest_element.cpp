#include <bits/stdc++.h>
using namespace std;

//Median of small arrays of size 5 or less than 5
int Median(int arr[], int n)
{
	sort(arr, arr + n);
	return arr[n / 2];
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//It searches for x in arr[l..h].....partition in L x S
int partition(int arr[], int l, int h, int x)
{
	// Search for x in arr[l..h] and move it to end
	int i;
	for (i = l; i < h; i++)
		if (arr[i] == x)
			break;
	swap(&arr[i], &arr[h]);

	//partition algorithm
	i = l;
	for (int j = l; j <= h - 1; j++)
	{
		if (arr[j] >= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[h]);
	return i;
}

int klargest(int arr[], int l, int h, int k)
{
	//k is smaller than number of elements in array
	if (k > 0 && k <= h - l + 1)
	{
		int n = h - l + 1; //number of elements

		int i, median[(n + 4) / 5]; // There will be floor((n+4)/5) groups;
									// dividing arr in groups of 5
		for (i = 0; i < n / 5; i++)
			median[i] = Median(arr + l + i * 5, 5);
		if (i * 5 < n) //For last group which has less than 5 elements
		{
			median[i] = Median(arr + l + i * 5, n % 5);
			i++;
		}
		// median of mediians
		int medOfMed = 0;
		if ((i == 1))
		{
			medOfMed = median[i - 1];
		}
		else
		{
			medOfMed = klargest(median, 0, i - 1, i / 2);
		}

		// correct position of medofmed
		int pos = partition(arr, l, h, medOfMed);

		// If position is same as k
		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1) // If position is more than k,recursive call for left subarray
			return klargest(arr, l, pos - 1, k);

		// Else recursive call for right subarray
		return klargest(arr, pos + 1, h, k - pos + l - 1);
	}

	// If k is more than number of elements in array
	return INT_MAX;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "K'th largest element is " << klargest(arr, 0, n - 1, k); //arr will be sorted in decreasing order
	return 0;
}
