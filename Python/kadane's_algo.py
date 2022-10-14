# User function Template for python3

class Solution:
    ##Complete this function
    # Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self, arr, N):
        ##Your code here
        ma = -100000000
        su = 0
        for i in arr:
            su += i
            if ma < su:
                ma = su
            if su < 0:
                su = 0

        return ma


# {
#  Driver Code Starts
# Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):
        n = int(input())

        arr = [int(x) for x in input().strip().split()]

        ob = Solution()

        print(ob.maxSubArraySum(arr, n))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends