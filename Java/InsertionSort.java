import java.util.Arrays;

class InsertionSort {

    public static void insertionSort(int[] arr) {
        int n = arr.length;

        for (int i = 1; i < n; i++) {
            int max = arr[i];
            int j = i - 1;

            while ((j > -1) && (arr[j] > max)) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = max;

        }
    }

    public static void main(String[] args) {
        int[] ar = {56, 12, 32, 87, 65, 54, 43, 32, 31, 2};
        System.out.println(Arrays.toString(ar));
        insertionSort(ar);
        System.out.println(Arrays.toString(ar));
    }
}