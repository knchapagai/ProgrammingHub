public class SelectionSort {
    //main function
    public static void main(String args[]){
        int[] arr={10,35,-15,7,55,1,-22};
        for(int i= arr.length-1;i>0;i--){
            int a=0;
            for(int j=1;j<=i;j++){
                if(arr[j]>arr[a]){
                    a=j;
                }
            }
            swap(arr,a,i);
        }
        print(arr);
    }
    //function for swapping the values
    public static void swap(int[] arr,int i,int j){
        if(i==j){
            return;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    //print function
    public static void print(int[] arr){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
