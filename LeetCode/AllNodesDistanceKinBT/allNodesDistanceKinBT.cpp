/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
                parent[current->left] = current;
            }
            if(current->right){
                q.push(current->right);
                parent[current->right] = current;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        getParents(root, parent);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int distance = 0;
        while(!q.empty()){
            if(distance == k) break;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    visited[current->left] = true;
                    q.push(current->left);
                }
                if(current->right && !visited[current->right]){
                    visited[current->right] = true;
                    q.push(current->right);
                }
                if(parent.find(current) != parent.end() && !visited[parent[current]]){
                    visited[parent[current]] = true;
                    q.push(parent[current]);
                }
            }
            distance++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};