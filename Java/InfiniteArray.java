package com.binarysearch;

public class InfiniteArray {
    public static void main(String[] args) {
        int[] arr = {2,3,5,6,7,8,9,12,14,15,17,46,78,98,122,123,435,2334,3466,24456};
        int target = 78;
        System.out.println(Result(arr,target));
    }
    static int Result(int[] arr, int target){
        int start = 0;
        int end = 1;
        while ( target > arr[end] ){
            int newStart = start;
            end = end + (end - start + 1)*2;
            start = newStart;
        }
        return binarySearch(arr,target,start,end);
    }
    static int binarySearch(int[] arr, int target, int start, int end) {
      while (start <= end) {
            int mid = end + ((start - end) / 2);
            if (arr[mid] < target) {
                start = mid + 1;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
