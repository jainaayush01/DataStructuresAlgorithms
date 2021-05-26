// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
// sum -> V
// wt -> coins
// N -> N
class Solution{
	public:
	int minCoins(int coins[], int N, int V) 
	{ 
	    long long int dp[N+1][V+1];
        for(int i = 0; i <= V; ++i) {
            dp[0][i] = INT_MAX; // Change 1  // to get sum zero we require zero coins
        }
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 0; // Change 2 // to get sum i with zero coins is not possible so infinite value
            // below part not required
            // if(coins[0] && i % coins[0] == 0) {
            //     dp[1][i] = i / coins[0];
            // }
            // else
            //     dp[1][i] = INT_MAX;
            
        }
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= V; ++j) {
                if(coins[i-1] <= j) {
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]); // 3rd change
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        long long int maxVal = INT_MAX;
        // for(int i = 0; i<=N; ++i) {
        //     for(int j=0; j<=V; ++j) {
        //         cout<<(dp[i][j] >=  maxVal ? -1 : dp[i][j])<<" ";
        //     }
        //     cout<<endl;
        // }
        return (dp[N][V] >= maxVal ? -1 : dp[N][V]);
	} 
	  
};