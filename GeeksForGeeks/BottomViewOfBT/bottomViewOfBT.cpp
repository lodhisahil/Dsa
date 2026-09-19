/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<pair<Node*, int>> q;
        map<int, int> m;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* current = it.first;
            int line = it.second;
            m[line] = current->data;
            if(current->left){
                q.push({current->left, line - 1});
            }
            if(current->right){
                q.push({current->right, line + 1});
            }
        }
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};