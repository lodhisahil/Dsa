/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:
    void getParent(Node* root, unordered_map<Node*, Node*>& parent){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* current = q.front();
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
    
    void findTargetNode(Node* root, int target, Node* & targetNode){
        if(root->data == target){
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
    
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parent;// child -> parent
        getParent(root, parent);
        Node* targetNode = NULL;
        findTargetNode(root, target, targetNode);
        
        int time = 0;
        queue<Node*> q;
        unordered_map<Node*, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* current = q.front();
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
