class Solution {
public:

    TreeNode* helper(vector<int>& preorder, int& i, int limit){
        if(i >= preorder.size() || preorder[i] > limit){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, limit);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};