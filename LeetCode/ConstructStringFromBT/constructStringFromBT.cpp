class Solution {
public:
    void helper(TreeNode* root, string& ans){
        if(root == NULL){
            return;
        }
        ans += to_string(root->val);
        if(root->left){
            ans += "(";
            helper(root->left, ans);
            ans += ")";
        }
        if(root->left == NULL && root->right){
            ans += "()";
        }
        if(root->right){
            ans += "(";
            helper(root->right, ans);
            ans += ")";
        }
    }
    string tree2str(TreeNode* root) {
        string ans = "";
        helper(root, ans);
        return ans;
    }
};