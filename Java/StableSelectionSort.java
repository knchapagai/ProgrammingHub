public class StableSelectionSort {
    //main function
    public static void main(String args[]) {
        int[] arr = {10, 35, -15, 7, 55, 1, -22};
        for (int i = 0; i < arr.length - 1; i++) {
            int min = i;
            for (int j = i + 1; j < arr.length; j++)
                if (arr[min] > arr[j])
                    min = j;
            int key = arr[min];
            while (min > i) {
                arr[min] = arr[min - 1];
                min--;
            }

            arr[i] = key;
        }
        print(arr);
    }
    //function to print the array
    public static void print(int[] arr){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
}