// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        int dp[N+1][sum+1];
        for(int j = 0; j <= sum; ++j) {
            dp[0][j] = 0;
        }
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= sum; ++j) {
                if(arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else {
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
        
        return dp[N][sum];
    }
};
