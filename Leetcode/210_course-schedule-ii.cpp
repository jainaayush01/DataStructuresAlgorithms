// 210 https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        // topological sort
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> ans(n);
        int count = 0;
        queue<int> q;
        
        for(auto x : pre) {
            int a = x[0], b = x[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            } 
        }
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            
            ans[count++] = v;
            
            for(int neighbor : adj[v]) {
                indegree[neighbor]--;
                
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if(count == n) {
            return ans;
        }
        else return {};
    }
};