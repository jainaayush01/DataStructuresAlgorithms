class Solution {
public:
    int solve(TreeNode* root, int &res) {
        if(root == NULL) {
            return -2000;
        }
        int leftSum = solve(root->left, res);
        int rightSum = solve(root->right, res);
        
        int temp = max((max(leftSum, rightSum) + root->val), root->val);
        res = max({res, leftSum + rightSum + root->val, temp});
        
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = -1001;
        solve(root, res);
        return res;
    }
};