class Solution {
public:
    string printLeastCommonSubsequence(string x, string y, int m, int n) {
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
        string ans = "";
        int i = m, j = n;
        while( i > 0 && j > 0 ) {
            if(x[i-1] == t[j-1]) {
                ans += x[i - 1];
                i--;
                j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    i = i - 1;
                }
                else {
                    j = j - 1;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}