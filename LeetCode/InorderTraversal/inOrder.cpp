class Solution {

void helper(TreeNode* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    helper(root->left, ans);
    ans.push_back(root->val);
    helper(root->right, ans);

    return;
}

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);

        return ans;
    }
};