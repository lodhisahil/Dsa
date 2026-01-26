class Solution {
public:

    TreeNode* prev = NULL;
    TreeNode* fir = NULL;
    TreeNode* sec = NULL;

    void inorder(TreeNode* root){
        if (root == NULL){
            return;
        }

        inorder(root->left);

        if(prev != NULL && root->val < prev->val){
            if(fir == NULL){
                fir = prev;
            }
                sec = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
       inorder(root);
       int temp = sec->val;

       sec->val = fir->val;
       fir->val = temp;
    }
};