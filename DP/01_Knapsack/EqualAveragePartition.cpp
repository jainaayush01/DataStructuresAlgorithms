class Solution {
public:
    vector<vector<int>> isSubsetSum(int N, vector<int> arr, int sum){
        // Dynamic Programming
        // 01 knapsack problem
        // choice: select the number or do not select the number
        int dp[N+1][sum+1];
        // dp[i][j] = displays is sum=j possible from
        // subset of the first i elements of arr

        // iniitalization:
        for(int j = 1; j <= sum; ++j) {
            dp[0][j] = 0; // sum=1...sum not possible from first 0 elements
        }
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 1; // sum=0 possible for first i=0...N by using empty subset
        }

        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= sum; ++j) {
                if(arr[i-1] <= j) { // check if arr[i-1] is less than sum
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    // if sum was possible from i-1 elements
                    // if not then if sum=j-arr[i-1] was possible from 0-1 elements
                }
                else { // if greater than the curr ans = previous ans
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(int i = 0; i <= N; ++i) {
        //     for(int j = 0; j <= sum; ++j) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        if(dp[N][sum]) {
          for(int i = 1; i <)
        }
        else return {}

        return dp[N][sum];
    }
    vector<vector<int>> canPartition(vector<int>& nums) {
        int total = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            total += nums[i];
        }
        if(total%2) {
            return false;
        }
        int sum = total/2;
        return isSubsetSum(n, nums, sum);
    }
};
