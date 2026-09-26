class Solution {
  public:
    void helper(Node* root, bool& ans){
        if(root == NULL || !ans){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        int left = root->left ? root->left->data : 0;
        int right = root->right ? root->right->data : 0;
        if(root->data != left + right){
            ans = false;
        }
        helper(root->left, ans);
        helper(root->right, ans);
    }
    bool isSumProperty(Node *root) {
        // code here
        bool ans = true;
        helper(root, ans);
        return ans;
    }
};