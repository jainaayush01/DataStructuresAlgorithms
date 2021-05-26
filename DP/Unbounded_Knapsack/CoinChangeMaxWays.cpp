// https://www.geeksforgeeks.org/coin-change-dp-7/
// sum -> m
// wt -> coins
// N -> N

class Solution {
public:
    long long int coinChangeMaxWays(int N, vector<int> coins, int m) {
        long long int dp[N+1][m+1];
        // initialization
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= m; ++i) {
            dp[0][i] = 1; // 1st change
        }
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(coins[i-1] <= j) {
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]; // 2nd change '+'
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][m];
    }
}