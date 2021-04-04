// 959 https://leetcode.com/problems/regions-cut-by-slashes/

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int size) {
        parent.resize(size);
        for(int i = 0; i < size; ++i) {
            parent[i] = i;
        }
        rank.resize(size, 0);
    }
    
    int find_set(int x) {
        if (parent[x] != x) parent[x] = find_set(parent[x]);
        return parent[x];
    }

    bool union_set(int x, int y) {
        int xr = find_set(x), yr = find_set(y);
        if (xr == yr) {
            return false;
        } 
        else if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
        } 
        else if (rank[xr] > rank[yr]) {
            parent[yr] = xr;
        } 
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

class Solution {
public:
    int n;
    int pos(int i, int j, int k) {
        return (i * n + j) * 4 + k;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        int total = n * n * 4;
        DSU dsu = DSU(total);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i > 0) {
                    dsu.union_set(pos(i, j, 0), pos(i-1, j, 2));
                }
                if(j > 0) {
                    dsu.union_set(pos(i, j, 3), pos(i, j-1, 1));
                }
                
                if(grid[i][j] != '/') {
                    dsu.union_set(pos(i, j, 0), pos(i, j, 1));
                    dsu.union_set(pos(i, j, 2), pos(i, j, 3));        
                }
                
                if(grid[i][j] != '\\') {
                    dsu.union_set(pos(i, j, 1), pos(i, j, 2));
                    dsu.union_set(pos(i, j, 0), pos(i, j, 3));        
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<total; ++i) {
            if(dsu.parent[i] == i) {
                ans++;
            }
        }
        return ans;
    }
};