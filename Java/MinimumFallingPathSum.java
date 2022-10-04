class MinimumFallingPathSum{
    public int[][] dp = new int[101][101];
    public int minFallingPathSum(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            Arrays.fill(dp[i],101);
        }
        int min =Integer.MAX_VALUE;
        for (int i = 0; i < matrix.length; i++) {
            min = Math.min(min,recursionForMPS(matrix[0][i],matrix,0,i));
        }
        return min;
    }
    public int recursionForMPS(int ele,int[][] matrix,int ind,int eleInd){
        if(ind >= matrix.length-1){
            return matrix[ind][eleInd];
        }
        if(dp[ind][eleInd] != 101){
            return dp[ind][eleInd];
        }
        int left = Integer.MAX_VALUE;
        int right = Integer.MAX_VALUE;
        if(eleInd > 0) {
            left = ele + recursionForMPS(matrix[ind+1][eleInd-1],matrix,ind+1,eleInd-1);
        }
        int mid = ele + recursionForMPS(matrix[ind+1][eleInd],matrix,ind+1,eleInd);;
        if(eleInd < matrix[0].length-1){
            right =  ele + recursionForMPS(matrix[ind+1][eleInd+1],matrix,ind+1,eleInd+1);
        }

        dp[ind][eleInd] = Math.min(left,Math.min(mid,right));
        return dp[ind][eleInd];
    }
}