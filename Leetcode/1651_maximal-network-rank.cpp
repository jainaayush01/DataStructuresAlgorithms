// 1615 https://leetcode.com/problems/maximal-network-rank/

class Solution {
 public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n);
        size_t res = 0;
        unordered_set<int> adj;
        for (auto r : roads) {
            ++cnt[r[0]];
            ++cnt[r[1]];
            adj.insert((min(r[0], r[1]) << 16) + max(r[0], r[1]));
        }
        for (auto i = 0; i < n; ++i)
            for (auto j = i + 1; j < n; ++j)
                res = max(res, cnt[i] + cnt[j] - adj.count((i << 16) + j));
        return res;
    }
};