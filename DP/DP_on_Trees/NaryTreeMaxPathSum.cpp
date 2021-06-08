class Solution {
public:
    int solve(Node* root, int &res) {
        if(root == NULL) {
            return 0;
        }
        int leftSum = solve(root->left, res);
        int rightSum = solve(root->right, res);
        
        int temp = root->data;
        if(root->left && root->right) {
            temp += max(leftSum, rightSum);
            int ans = leftSum + rightSum + root->data;
            res = max(res, ans);
        }
        else if(!root->left) {
            temp += rightSum;
        }
        else if(!root->right) {
            temp += leftSum;
        }
        
        return temp;
    }
    int maxPathSum(Node* root) {
        int res = INT_MIN;
        int ret = solve(root, res);
        if(res == INT_MIN) {
            return ret;
        }
        return res;
    }
};