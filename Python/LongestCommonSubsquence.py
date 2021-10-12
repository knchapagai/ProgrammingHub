def longestCommonSubsequence(text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)
        dp = [[-1 for _ in range(m+1)] for _ in range(n+1)]
        def lcs(text1, text2):
            n = len(text1)
            m = len(text2)
            if len(text1) == 0 or len(text2) ==0:
                dp[n][m] =0
                return 0
            
            if (dp[n][m] != -1):
                return dp[n][m]
		        
            
            if text1[-1] == text2[-1]:
                dp[n][m] = 1+ lcs(text1[:-1], text2[:-1])
                return dp[n][m]

            else:
                dp[n][m]= max(lcs(text1, text2[:-1]), lcs(text1[:-1], text2))
                return dp[n][m]
        return lcs(text1,text2)
 
print(longestCommonSubsequence("Hello","Hell"))   