/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<vector<int>> treeTraversal(TreeNode* root){
			//your code goes here
            vector<int> preorder;
            vector<int> inorder;
            vector<int> postorder;
            stack<pair<TreeNode*, int>> st;
            st.push({root, 1});
            while(!st.empty()){
                auto it = st.top();
                st.pop();
                //preorder
                if(it.second == 1){
                    preorder.push_back(it.first->data);
                    it.second++;
                    st.push(it);
                    if(it.first->left){
                        st.push({it.first->left, 1});
                    }
                }
                //inorder
                else if(it.second == 2){
                    inorder.push_back(it.first->data);
                    it.second++;
                    st.push(it);
                    if(it.first->right){
                        st.push({it.first->right, 1});
                    }
                }
                //postorder
                else {
                    postorder.push_back(it.first->data);
                }
            }
            return {inorder, preorder, postorder};
		}
};