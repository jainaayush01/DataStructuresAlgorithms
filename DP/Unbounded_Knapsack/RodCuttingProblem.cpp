// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#

class Solution{
  public:
    int cutRod(int price[], int N) {
        int dp[N+1][N+1];
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= N; ++i) {
            dp[0][i] = 0;
        }
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(i <= j) {
                    dp[i][j] = max(price[i-1] + dp[i][j-i], dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][N];
    }
};