class Solution {
public:
    // supersequence of two sequences X and Y is the sequence which has X and Y as subsequences
    // to find shortest supersequence we should not repeat common characters
    // So we remove the common repeated char from MAX Length supersequence possible(m+n)
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
    string shortestCommonSupersequence(string x, string y, int m, int n) {
        int lcs = longestCommonSubsequence(x, y, m, n);
        return m + n - lcs;
    }
}