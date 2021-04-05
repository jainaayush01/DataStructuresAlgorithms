// 1267 https://leetcode.com/problems/count-servers-that-communicate/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        // see in each col and row for > 2 servers and count those
        
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<int> row(m, 0), col(n, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1 && (row[i] > 1 || col [j] > 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};