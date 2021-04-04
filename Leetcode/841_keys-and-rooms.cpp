// 841 https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    vector<int> visited;
    void dfs(vector<vector<int>> rooms, int v) {
        visited[v] = 1;
        for(auto x : rooms[v]) {
            if(!visited[x])
                dfs(rooms, x);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size(), 0);
        dfs(rooms, 0);
        for(auto v : visited) {
            if(v == 0) {
                return false;
            }
        }
        return true;
    }
};