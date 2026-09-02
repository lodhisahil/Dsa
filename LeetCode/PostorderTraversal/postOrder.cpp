class Solution {
public:

void helper(TreeNode* root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    helper(root->left, ans);
    helper(root->right, ans);
    ans.push_back(root->val);

    return;
}

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);

        return ans;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        if(root == NULL){
            return ans;
        }
        st1.push(root);
        while(!st1.empty()){
            TreeNode* current = st1.top();
            st1.pop();
            st2.push(current);
            if(current->left){
                st1.push(current->left);
            }
            if(current->right){
                st1.push(current->right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        TreeNode* temp;
        stack<TreeNode*> st;
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }else{
                temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
};
