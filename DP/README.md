# Dynamic Programming Notes

### Where dp can be used?
> 1. Choice is given
> 2. Find optimal solution

### How to solve dp problems
> 1. Recursion
> 2. Recursion + Memoization
> 3. Top down approach
> 4. Bottom up approach

## types of dp problems
1. 01 knapsack(6)
2. Unbounded knapsack(5)
3. Fibonacci(7)
4. LCS(15)
5. LIS(10)
6. Kadane's Algorithm(6)
7. Matrix chain multiplication(7)
8. DP on Tress(4)
9. DP on Grid(14)
10. Others(5)


# 1. 01 knapsack
[Link](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/);
##### Input:

```
wt[]: array of weights available

val[]: value of the subsequent weight 

N: number of weights

capacity/sum: maximum sum of weights knapsack can hold
```

##### Problem:

```
choose the weight once or leave it
optimal: choose weights with maximum value with total weight less than given weight/sum
```

##### Code:

```
    int knapsack01(int N, vector<int> wt, vector<int> val, int sum) {
        int dp[N+1][sum];
        // initialization
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= sum; ++i) {
            dp[0][i] = 0;
        }
        for(int i = 0; i <= N; ++i) {
            for(int i = 0; i <= sum; ++i) {
                if(wt[i-1] <= j) {
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
    }
```

#### Practice problems similar to 01 knapsack.
1. [Subset sum](https://www.geeksforgeeks.org/subset-sum-problem-dp-25/)
2. [Equal Subset sum partition problem](https://www.geeksforgeeks.org/partition-problem-dp-18/)
3. [Count of subset sum with a given sum](https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/)
4. [Minimum subset sum difference](https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/)
5. [count the number of subsets with a given difference]()
6. [target sum problem](https://leetcode.com/problems/target-sum/)

NOTE: Solutions are for your reference and available in the DP Folder

# 2. Unbounded knapsack

##### Input:

```
wt[]: array of weights available

val[]: value of the subsequent weight 

N: number of weights

capacity/sum: maximum sum of weights knapsack can hold
```

##### Problem:
[Link](https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/)

```
you can choose the weight multiple times or leave it
optimal: choose weights with maximum value with total weight less than given weight/sum
```

##### Code:

```
    int knapsack01(int N, vector<int> wt, vector<int> val, int sum) {
        int dp[N+1][sum];
        // initialization
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= sum; ++i) {
            dp[0][i] = 0;
        }
        for(int i = 0; i <= N; ++i) {
            for(int i = 0; i <= sum; ++i) {
                if(wt[i-1] <= j) {
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]); // only change than 01 knapsack
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
    }
```

#### Unbounded knapsack Practice problems with similarity