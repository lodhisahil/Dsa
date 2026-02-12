class Solution {
public:
    TreeNode* prev = NULL;
    
    int minDiffInBST(TreeNode* root) {
        if(root == NULL){
            return INT_MAX;
        }

        int ans = INT_MAX;
        if(root->left){
            int leftDiff = minDiffInBST(root->left);
            ans = min(ans, leftDiff);
        }
        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        if(root->right){
            int rightDiff = minDiffInBST(root->right);
            ans = min(ans, rightDiff);
        }
        return ans;
    }
};