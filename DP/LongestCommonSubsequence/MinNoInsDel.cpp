class Solution{
	public:
	int longestCommonSubsequence(string x, string y, int m, int n) {
        int dp[m+1][n+1];
        for(int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(x[i-1] == y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
	int minOperations(string x, string y) 
	{ 
	    int m = x.size(), n = y.size();
	    int lcs = longestCommonSubsequence(x, y, m, n);
	    int operations = m - lcs + n - lcs; // delete extra other than common in x and insert extra other than common from y in x
	    return operations;
	} 
};