class Solution {
public:
    int solve(Node* root, int &res) {
        if(root == NULL) {
            return 0;
        }
        int leftDiam = solve(root->left, res);
        int rightDiam = solve(root->right, res);
        res = max(res, leftDiam + rightDiam + 1);
        return 1 + max(leftDiam, rightDiam);
    }
    int diameter(Node* root) {
        int res = -1;
        solve(root, res);
        return res;
    }
};
