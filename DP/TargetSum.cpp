// 494 https://leetcode.com/problems/target-sum/

class Solution {
public:
    int countSubsetSum(int N, vector<int> arr, int sum){
        // Dynamic Programming
        // 01 knapsack problem
        // choice: select the number or do not select the number
        int dp[N+1][sum+1]; 
        // dp[i][j] = displays is sum=j possible from 
        // subset of the first i elements of arr
        
        // iniitalization: 
        for(int j = 1; j <= sum; ++j) {
            dp[0][j] = 0; 
            // sum=1...sum not possible from first 0 elements
        }
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 1; 
            // sum=0 possible for first i=0...N by using empty subset
        }
        
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= sum; ++j) {
                if(arr[i-1] == 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else if(arr[i-1] <= j) { // check if arr[i-1] is less than sum
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]; 
                    // if sum was possible from i-1 elements 
                    // if not then if sum=j-arr[i-1] was possible from 0-1 elements
                    // dp[i-1][j] tells if the subset was formed without arr[i-1] or not
                    // so basially dp[N][sum] tells us by going through all the subsets
                }
                else { 
                    // if greater than the curr ans = previous ans
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        for(int i=0; i<=N;++i) {
            for(int j=0; j<=sum;++j) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[N][sum];
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        // s1 and s2 = sum of 2 subsets of arr
        // s1-s2 = diff = target
        // s1+s2 = totalSum
        // s1 = (diff+totalSum)/2
        // countSubsetSum(s1);

        int totalSum = 0, cnt = 0;
        int N = arr.size();
        for(int i = 0; i < N; ++i) {
            totalSum += arr[i];
            if(arr[i] == 0) {
                cnt++;
            }
        }
        if((target + totalSum) % 2) {
            return 0;
        }
        int sum1 = (target + totalSum) / 2;
        return pow(2,cnt) * countSubsetSum(N, arr, sum1);
    }
};