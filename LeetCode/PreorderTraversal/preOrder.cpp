class Solution {
public:

void helper(TreeNode* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    ans.push_back(root->val);
    helper(root->left, ans);
    helper(root->right, ans);

    return;
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);

        return ans;
    }
};

class Solution {
public:   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* current = st.top();
            ans.push_back(current->val);
            st.pop();
            if(current->right){
                st.push(current->right);
            }
            if(current->left){
                st.push(current->left);
            }
        }
        return ans;
    }
};