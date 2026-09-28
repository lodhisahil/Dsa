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
    unordered_map<string, int> mp;
    unordered_map<int, int> cnt;
    vector<TreeNode*> ans;
    int id = 1;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        string s = to_string(root->val) + "," + to_string(solve(root->left)) + "," + to_string(solve(root->right));
        if(!mp.count(s)){
            mp[s]=id++;
        }
        int x=mp[s];
        if(++cnt[x]==2){
            ans.push_back(root);
        }
        return x;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};