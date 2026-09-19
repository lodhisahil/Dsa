/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        map<int, int> mapp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* current = it.first;
            int line = it.second;
            if(mapp.find(line) == mapp.end()){
                mapp[line] = current->data;
            }
            if(current->left){
                q.push({current->left, line - 1});
            }
            if(current->right){
                q.push({current->right, line + 1});
            }
        }
        for(auto it : mapp){
            ans.push_back(it.second);
        }
        return ans;
    }
};