// 207 https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        
        // Typical Topological Sort Question
        // convert into adjacency list and do the top sort
        
        vector<int> v[n];
        vector<int> in(n,0);
        int count=0;
        for(int i=0;i<p.size();i++)
        {
            v[p[i][0]].push_back(p[i][1]);
            in[p[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(in[i]==0)    q.push(i);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            for(int node:v[curr])
            {
                in[node]--;
                if(in[node]==0)
                    q.push(node);
            }
        }
        return count==n;
    }
};