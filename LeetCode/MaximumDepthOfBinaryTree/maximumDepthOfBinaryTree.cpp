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
// ###### MY APPROACH ######
class Solution {
public:
    void helper(TreeNode* root, int val, int& height){
        if(root == NULL){
            return;
        }
        val++;
        height = max(height, val);
        helper(root->left, val, height);
        helper(root->right, val, height);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int height = INT_MIN;
        helper(root, 0, height);
        return height;
    }
};

// ###### SIMPLER APPROACH ######
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};