class Solution {
public:
    int solve(Node* root, int &res) {
        if(root == NULL) {
            return -2001;
        }
        int leftSum = solve(root->left, res);
        int rightSum = solve(root->right, res);
        
        int temp = max(leftSum, rightSum) + root->data;
        if(root->left == NULL && root->right == NULL) {
            temp = root->data;
            return temp;
        }
        int ans = leftSum + rightSum + root->data;
        res = max(res, ans);
        
        return temp;
    }
    int maxPathSum(Node* root) {
        int res = -1001;
        solve(root, res);
        return res;
    }
};