// 897 https://leetcode.com/problems/increasing-order-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Inorder Traversal Recursion
    // traversing inorder and when left node is visted we 
    // no longer need it as it is already pointed with help of curr
    // and in ans we don't need left so null
    // and then we are at the current node as all element right to it and 
    // above it are bigger than current node so it is next element and 
    // then visit the right node
    TreeNode* curr;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* nroot = new TreeNode(-1);
        curr = nroot;
        inorder(root);
        return nroot->right;
    }
    
    void inorder(TreeNode* node) {
        if(node == NULL) return;
        inorder(node->left);
        node->left = NULL;
        curr->right = node;
        curr = node;
        inorder(node->right);
    }
};