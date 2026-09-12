/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isLeaf(Node* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        return false;
    }
    void leftBoundary(Node* root, vector<int>& ans){
        Node* curr = root;
        while(curr){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
            if(curr->left){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
    }
    void rightBoundary(Node* root, vector<int>& ans){
        vector<int> temp;
        Node* curr = root->right;
        while(curr){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        //reverseing
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }
    void addLeaves(Node* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        if(isLeaf(root)){
            ans.push_back(root->data);
            return ans;
        }
        ans.push_back(root->data);
        if(root->left){
            leftBoundary(root->left, ans);
        }
        addLeaves(root, ans);
        if(root->right){
            rightBoundary(root, ans);
        }
        return ans;
    }
};