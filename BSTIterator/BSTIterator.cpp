class BSTIterator {
public:
    stack<TreeNode*> s;
    void leftNodes(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
 
    BSTIterator(TreeNode* root) {
        leftNodes(root);
    }
    
    int next() {
        TreeNode* ans = s.top();
        s.pop();
        if(ans->right){
            leftNodes(ans->right);
        }
        return ans->val;
    }
    
    bool hasNext() {
        return s.size() > 0;
    }
};