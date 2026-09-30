/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
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

    void findTargetNode(TreeNode* root, int target, TreeNode* & targetNode){
        if(root->val == target){
            targetNode = root;
            return;
        }
        if(root->left){
            findTargetNode(root->left, target, targetNode);
        }
        if(root->right){
            findTargetNode(root->right, target, targetNode);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;// child -> parent
        getParent(root, parent);
        TreeNode* targetNode = NULL;
        findTargetNode(root, start, targetNode);
        
        int time = 0;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                   q.push(current->left);
                   visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                   q.push(current->right);
                   visited[current->right] = true;
                }
                if(parent[current] && !visited[parent[current]]){
                   q.push(parent[current]);
                   visited[parent[current]] = true;
                }
            }
            time++;
        }
        return time - 1;
    }
};