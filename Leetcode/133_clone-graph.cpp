// 133. https://leetcode.com/problems/clone-graph  //deep copy not shallow copy

class Solution {
public:
    unordered_map<Node*, Node*> mp; // its containing copies of corresponding Nodes
    
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        // If a node is not created again means it is not visited
        // then we create that node and also add its neighbors and clone them too
        if (mp.find(node) == mp.end()) {
            mp[node] = new Node(node -> val, {});
            for (auto x : node->neighbors) {
                mp[node] -> neighbors.push_back(cloneGraph(x));
            }
        }
        return mp[node];
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/