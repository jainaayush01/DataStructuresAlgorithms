// 785 https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    vector<int> visited, part;
    bool bfs(vector<vector<int>> graph, int i) {
        int n = graph.size();
        queue<int> q;
        q.push(i);
        part[i] = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            visited[v] = 1;
            for(int x : graph[v]) {
                if(part[x] == 2) {
                    part[x] = (part[v] == 0 ? 1 : 0);
                    q.push(x);
                }
                else if(part[x] == part[v]) {
                    return false;
                }
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool ret = 1;
        
        visited.resize(n, 0);
        part.resize(n, 2);
        for(int i = 0; i < n; ++i) {    
            if(visited[i] == 1) {
                continue;
            }
            ret = bfs(graph, i);
            if(!ret) return ret;
        }
        return ret;
    }
};