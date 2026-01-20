
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            for(int i=0; i<s; i++){
            TreeNode* current = q.front();
            q.pop();
            if(current->left != NULL)q.push(current->left);
            if(current->right != NULL)q.push(current->right);
            temp.push_back(current->val);
            }
            ans.push_back(temp);

           
        }
        return ans;
    }
};