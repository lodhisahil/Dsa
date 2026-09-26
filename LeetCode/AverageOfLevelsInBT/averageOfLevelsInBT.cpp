class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double sum = 0;
            for(int i=0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();
                sum += current->val;
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
            ans.push_back(sum / size);
        }
        return ans;
    }
};