class Solution {
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
	int lps(string x) 
	{
        string y = x;
        reverse(y.begin(), y.end());
        int m = x.size(), n = m;
        return longestCommonSubsequence(x, y, m, n);
	} 
    int minimumNumberOfInsertions(string S) {
        return S.size() - lps(S);
    } 
}