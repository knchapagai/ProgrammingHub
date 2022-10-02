<-----Question---->

You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

 

Example 1:


Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
Example 2:


Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
Example 3:


Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.



<----INTUTION AND ALGORITHM---->



/* Non-formal proof that median is correct:
 Sort all the elements and find the median. Compute the differences from the median. Is that the best we can do? Well, choose one number less than the median and compute the 
 differences... in that case everything smaller than that new number has a smaller difference by the amount of the new (not quite) median compared to the median. But all the 
 numbers greater than that new number have an increased difference by that exact same amount. Unfortunately, since your chosen number was smaller than the median you have improved 
 fewer numbers than you have hurt — the median has as many smaller numbers as larger numbers, but you are computing with fewer smaller numbers and more larger numbers, by 
 definition compared to the median. Run the same experiment by choosing the number one larger than the median: you have improved the (now fewer) number of large numbers but have 
 hurt the (now greater quantity) of smaller numbers. Again a loss.*/
  
  <-----SOLUTION------>
  
  
  

class Solution {
    public int minOperations(int[][] grid, int x) {
        ArrayList<Integer> al = new ArrayList<>();
        int rows = grid.length,cols = grid[0].length;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                al.add(grid[i][j]);
            }
        }
        Collections.sort(al);
        int median = al.get((al.size()-1)/2);
        int count = 0;
        for(int i : al){
            if(i!=median){
                int diff = Math.abs(i-median);
                if(diff%x!=0) return -1;
                count += diff/x;
            }   
        }
        return count;
    }
}
