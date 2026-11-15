class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    void solve(TreeNode* root, vector<vector<string>>& res, int r, int c, int h) {
        if(root == NULL) {
            return;
        }
        res[r][c] = to_string(root->val);
        if(r == h) {
            return;
        }
        int offset = 1 << (h - r - 1);
        solve(root->left, res, r + 1, c - offset, h);
        solve(root->right, res, r + 1, c + offset, h);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int m = h + 1;
        int n = (1 << (h + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        solve(root, res, 0, (n - 1) / 2, h);
        return res;
    }
};