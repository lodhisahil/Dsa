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
    void helper(TreeNode* root, int targetSum, int sum, vector<int>& ds, vector<vector<int>>& ans){
        if((root->left == NULL && root->right == NULL)){
            if(sum == targetSum){
                ans.push_back(ds);
            }
            return;
        }
        if(root->left){
            ds.push_back(root->left->val);
            helper(root->left, targetSum, sum + root->left->val, ds, ans);
            ds.pop_back();
        }
        if(root->right){
            ds.push_back(root->right->val);
            helper(root->right, targetSum, sum + root->right->val, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        vector<int> ds;
        ds.push_back(root->val);
        helper(root, targetSum, root->val, ds, ans);
        return ans;
    }
};