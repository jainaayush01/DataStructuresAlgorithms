// Problem: https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        // Approach  1
        // If a trusts b we make an edge from a->b
        // Incoming Edge for b as b is trusted by a
        // Outgoing edge for a as a trusts b
        // If Person has 0 outgoing edges and N-1 incoming edges
        // Then it is the judge but we need to check for judges>1
        
        // Approach 2
        // You can check if InDegree - OutDegree == N-1
        
        vector<int> cnt(N, 0);
        int edges = trust.size();
        int judge = -1;
        
        for(int i=0; i<edges; ++i) {
            int a = trust[i][0];
            int b = trust[i][1];
            cnt[a-1]--;
            cnt[b-1]++;
        }
        
        for(int i = 0; i < N; ++i) {
            if(cnt[i] == N-1) {
                judge = i+1;
            }
        }
        
        return judge;
    }
};
