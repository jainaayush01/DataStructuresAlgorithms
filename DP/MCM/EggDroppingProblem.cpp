class Solution {
public:
    int dp[101][10001];
    int solve(int k, int n) {
        if(n == 0 || n == 1 || k == 1) {
            return n;
        }
        if(dp[k][n] != -1) {
            return dp[k][n];
        }
        int ans = INT_MAX, l = 1, h = n;
        while(l <= h) {
            int i = l + (h- l)/2;
            if(dp[k - 1][i - 1] == -1) {
                dp[k - 1][i - 1] = solve(k - 1, i - 1);
            }
            if(dp[k][n - i] == -1) {
                dp[k][n - i] = solve(k, n - i);
            }
            int temp = 1 + max(dp[k-1][i-1], dp[k][n - i]);

            if(dp[k - 1][i - 1] >= dp[k][n - i]) {
                h = i - 1;
            }
            else {
                l = i + 1;
            }
            
            ans = min(ans, temp);
        }
        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        int ret = solve(k, n);
        return ret;
    }
};