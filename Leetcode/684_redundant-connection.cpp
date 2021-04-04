// 684 https://leetcode.com/problems/redundant-connection/

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int size) {
        parent.resize(size);
        for(int i = 0; i < size; ++i) {
            parent[i] = i;
        }
        rank.resize(size);
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // we simply find the first edge occurring in the graph that is already connected
        DSU dsu = DSU(1001);
        for(auto edge : edges) {
            if(!dsu.union_set(edge[0], edge[1])) {
                return edge;
            }
        }
        return {-1};
    }
};