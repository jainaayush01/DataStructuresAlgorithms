// 1791 https://leetcode.com/problems/find-center-of-star-graph/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Since there are exactly n-1 edges
        // therefore no need to check every edge.
        // center will be in every node
        // so using any two nodes we can find out
        
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }
        return edges[0][1];
    }
};