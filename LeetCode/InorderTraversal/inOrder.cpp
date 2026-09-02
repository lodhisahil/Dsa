class Solution {

void helper(TreeNode* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    helper(root->left, ans);
    ans.push_back(root->val);
    helper(root->right, ans);

    return;
}

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);

        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        TreeNode* current = root;
        stack<TreeNode*> st;
        while(true){
            if(current != NULL){
                st.push(current);
                current = current->left;
            }else{
                if(st.empty()){
                    break;
                }
                current = st.top();
                st.pop();
                ans.push_back(current->val);
                current = current->right;
            }
        }
        return ans;
    }
};