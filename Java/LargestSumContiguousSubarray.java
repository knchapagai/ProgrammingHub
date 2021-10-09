class Main{
    static int maxSumSubArray(int a[]){
        int maxSum=0;
        int currSum=0;
        for(int i=1;i<a.length;i++){
            currSum=currSum+a[i];
            if(currSum>maxSum){
                maxSum=currSum;
            }
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
    public static void main (String[] args) {
       int []a={-2,-3,4,-1,-2,1,5,-3};
      System.out.println("Maximum contiguous sum is "+maxSumSubArray(a));
    }
}