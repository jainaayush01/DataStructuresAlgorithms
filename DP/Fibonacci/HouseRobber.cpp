// https://leetcode.com/problems/house-robber/
// relation: dp[n] = max(dp[n-1], nums[n] + max(dp[n-3], dp[n-2]))

class Solution {
public:
    int rob(vector<int>& nums) {
        // Time: O(n), Space: O(n);
        int n = nums.size();
        int dp[n+1];
        nums.push_back(0); // avoid nums[n] error

        if(n < 3) return max(nums[0], nums[1]);

        dp[0] = nums[0];
        dp[1] = nums[1],
        dp[2] = dp[0] + nums[2];
        for(int i = 3; i <= n; ++i) {
            dp[i] = max(dp[i-1], nums[i] + max(dp[i-2], dp[i-3]));
        }

        return dp[n];
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int exclude = 0;
        int include = nums[0];
        int ans = max(exclude, include);
        for(int i = 1; i < nums.size(); i++){
            ans = max(exclude + nums[i], include);
            int temp = include;
            include = exclude + nums[i];
            exclude = max(exclude, temp);
        }

        return ans;
    }
};
