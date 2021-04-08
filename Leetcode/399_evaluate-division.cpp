// 399 https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> res;
        
        int n = eq.size();
        for(int i = 0; i < n; ++i) {
            double val = values[i];
            graph[eq[i][0]].insert(make_pair(eq[i][1], val));
            if(val)
                graph[eq[i][1]].insert(make_pair(eq[i][0], 1/val));
        }
        
        for(auto i : queries) {
            unordered_set<string> visited;
            double tmp = dfs(i[0],i[1],graph,visited);
            if(tmp) res.push_back(tmp);
            else res.push_back(-1);
        }
        
        return res;
    }
    double dfs(string start, string end, unordered_map<string,unordered_map<string, double>> graph, unordered_set<string> &visited) {
        if(graph[start].find(end) != graph[start].end()) {
            return graph[start][end];
        }
        
        for (auto x : graph[start]) {
            if(visited.find(x.first) == visited.end()) {
                visited.insert(x.first);
                double tmp = dfs(x.first, end, graph, visited);
                if(tmp) {
                    return x.second*tmp;
                }
            }
        }
        return 0;
    }
};