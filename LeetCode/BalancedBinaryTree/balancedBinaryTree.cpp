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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(abs(leftHeight - rightHeight) > 1){
            return false;
        }
        if(isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};

// OPTIMAL APPROACH 
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh == -1 || rh == -1 || abs(lh-rh) > 1){
            return -1;
        }
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {    
        return height(root) == -1 ? false : true;
    }
};