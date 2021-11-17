// https://www.interviewbit.com/problems/0-1-knapsack/
class Solution {
    int knapsack01(int N, vector<int> wt, vector<int> val, int sum) {
        int dp[N+1][sum+1];
        // initialization
        // dp[i][j] denotes the total weight if i
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= sum; ++i) {
            dp[0][i] = 0;
        }
        for(int i = 0; i <= N; ++i) {
            for(int j = 0; j <= sum; ++j) {
                if(wt[i-1] <= j) {
                    // two option select or dont select
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else {
                    // dont select the element
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[N][sum];
    }
};
