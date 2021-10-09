def longestCommonSubstring(text1, text2):
        n = len(text1)
        m = len(text2)
        dp = [[-1 for _ in range(m+1)] for _ in range(n+1)]
        
        for i in range(n+1):
            for j in range(m+1):
                if i==0 or j==0:
                    dp[i][j] = 0
                    continue
                
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = 1+ dp[i-1][j-1]
                    
                else:
                    dp[i][j] = 0
        return dp[-1][-1]
    
print(longestCommonSubstring("Hello", "Hello"))