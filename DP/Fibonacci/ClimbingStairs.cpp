// https://leetcode.com/problems/climbing-stairs/
// relation dp[n] = dp[n-1] + dp[n-2]
class Solution {
public:
    int climbStairs(int n) {
        // DP Space: O(n) Time: O(n);
        if(n<=3)    return n;
        int dp[n+1];
        dp[0]=0; dp[1]=1;

        for(int i=2; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


// https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        // Var Space: O(1) Time: O(n);
        if(n<=3)    return n;
        int a = 0, b = 1, c;

        for(int i=2; i<=n; ++i) {
            c = a + b;
            a = b; b = c;
        }
        return c;
    }
};
