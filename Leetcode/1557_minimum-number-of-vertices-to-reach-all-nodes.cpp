class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        // We only need to find the nodes which are not reachable 
        // by any other nodes and then they will automatically 
        // be able to reach all the nodes.
        // since there is no cycle (acyclic) and graph is directed
        // thus atleast 1 of nodes will have indegree of 0 
        
        // Less Storage 2nd one no need to store which nodes are sending incoming edge
        
        vector<int> in(n);
        
        for(auto x : edges) {
            in[x[1]]++;
        }
        
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            if(in[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};