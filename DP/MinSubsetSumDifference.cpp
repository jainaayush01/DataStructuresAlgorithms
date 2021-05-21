// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution{

    // similarity: to equal sum partition problem
    // here we have to find minimum differenece between s1 and s2 
    // there we had to find out s1-s2=0
    // last row of dp matrix contains what subsetSums are possible with arr of size N
    // so we can take the max sum possible and find diff: totalSum - 2 * subsetSum

	public:
	int subsetSum(int N, int arr[], int sum){
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
                    // dp[i-1][j] tells if the subset was formed without arr[i-1] or not
                    // so basially dp[N][sum] tells us by going through all the subsets
                }
                else { // if greater than the curr ans = previous ans
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        for(int j = sum; j >= 0; --j) {
            if(dp[N][j]) {
                return j;
            }
        }
        
    }
	int minDiffernce(int arr[], int n) 
	{ 
	    int totalSum = 0;
	    for(int i = 0; i < n; ++i) {
	        totalSum += arr[i];
	    }
	    int sum1 = subsetSum(n, arr, totalSum/2);
	    return totalSum - 2*sum1;
	} 
};