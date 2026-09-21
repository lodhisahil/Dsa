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
    void helper(TreeNode* root, int curr, int& ans){
        if(root == NULL){
            return;
        }
        curr = curr * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            //leaf node 
            ans += curr;
            return;
        }
        if(root->left){
            helper(root->left, curr, ans);
        }
        if(root->right){
            helper(root->right, curr, ans);
        }
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};