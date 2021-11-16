// https://leetcode.com/problems/min-cost-climbing-stairs
// relation: dp[n] = cost[i] min(dp[n-1], p[n-2]);

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // DP Problem Type: Fibonacci
        // Time: O(n) Space: O(n)

        int n = cost.size();
        int dp[n+1];
        cost.push_back(0);  // avoid cost[n] error

        dp[0] = cost[0], dp[1] = cost[1];

        for(int i = 2; i <= n; ++i) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return dp[n];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // DP Problem Type: Fibonacci
        // var - Time: O(n) Space: O(1)

        int n = cost.size();
        int a = cost[0], b = cost[1], c;
        cost.push_back(0); // avoid cost[n] error

        for(int i = 2; i <= n; ++i) {
            c = cost[i] + min(a, b);
            a = b; b = c;
        }

        return c;
    }
};
