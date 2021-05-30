class LongestCommonSubstring {class Solution{
    public:
    // similar to leastCommonSubsequence
    // here we have to find continuos common strings
    // so whenever 2 elements are not same we will fill that cell wih zero
    // and we will return max value in matrix
    
    int longestCommonSubstr (string x, string y, int m, int n)
    {
        int dp[m+1][n+1];
        for(int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }

        int ret = -1;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(x[i-1] == y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 0;
                }
                ret = max(ret, dp[i][j]);
            }
        }
        
        return ret;
    }
};