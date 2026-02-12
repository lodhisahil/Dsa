class Solution {
public:
    int ans = 0;
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftH = height(root->left);
        int rightH = height(root->right);
        ans = max(ans, leftH + rightH);
        
        return max(leftH, rightH) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return ans;
    }
};