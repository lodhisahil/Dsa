class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while(q.size() > 0){
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maxWidth = max(maxWidth, (int)(endIdx-stIdx+1));
            int size = q.size();
            for(int i=0; i<size; i++){
                auto currNode = q.front();
                q.pop();
                if(currNode.first->left){
                    q.push({currNode.first->left, 2*currNode.second+1});
                }
                if(currNode.first->right){
                    q.push({currNode.first->right, 2*currNode.second+2});
                }
            }
        }
        return maxWidth;
    }
};