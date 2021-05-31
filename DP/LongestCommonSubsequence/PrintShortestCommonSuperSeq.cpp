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
        string ans = "";
        int i = m, j = n;
        while( i > 0 && j > 0 ) {
            if(x[i-1] == y[j-1]) {
                ans += x[i - 1]; // whenever we enquire common letter we only print it once
                i--;
                j--;
            }
            else { // otherwise we print the letter which is not going to be visited again as we are moving upwards
                if(dp[i-1][j] > dp[i][j-1]) {
                    ans += x[i - 1];
                    i = i - 1;
                }
                else {
                    ans += y[j - 1];
                    j = j - 1;
                }
            }
        }
        while( i > 0) {
            ans += x[i - 1];
            i--;
        }
        while(j > 0) {
            ans += y[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string printShortestCommonSupersequence(string x, string y, int m, int n) {
        string pscs = longestCommonSubsequence(x, y, m, n);
        return pscs;
    }
}