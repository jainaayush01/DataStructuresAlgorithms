// 1631 https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    // dijkstra's algorithm
    int dirs[5] = {0, 1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<int>> eff(m, vector<int> (n, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push(make_pair(0, make_pair(0, 0))); // effort, row, col for 0;
        
        while(!pq.empty()) {
            pair<int, pair<int,int>> v = pq.top();
            int effort = v.first, r = v.second.first, c = v.second.second;
            pq.pop();
            
            if(r == m-1 && c == n-1) {
                return effort;
            }
            if(effort >= eff[r][c]) {
                continue;
            }
            eff[r][c] = effort;
            
            for(int i = 0; i < 4; ++i) {
                int x = r + dirs[i], y = c + dirs[i+1];
                if(x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }
                int ne = max(effort, abs(heights[r][c] - heights[x][y]));
                pq.emplace(make_pair(ne, make_pair(x, y)));
            }
        }
        return -1; 
    }
};

