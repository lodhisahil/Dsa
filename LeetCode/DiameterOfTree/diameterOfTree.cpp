// class Solution {
// public:
//     int ans = 0;
//     int height(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//         int leftH = height(root->left);
//         int rightH = height(root->right);
//         ans = max(ans, leftH + rightH);
        
//         return max(leftH, rightH) + 1;
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         height(root);

//         return ans;
//     }
// };

// OPTIMALLY BETTER APPROACH
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
    int height(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left, ans);
        int rh = height(root->right, ans);
        ans = max(ans, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);
        return ans;
    }
};