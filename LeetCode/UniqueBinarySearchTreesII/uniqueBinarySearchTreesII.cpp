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
    vector<TreeNode*> generateTrees(int n) {
        memo.assign(n + 2, vector<vector<TreeNode*>>(n + 2));
        done.assign(n + 2, vector<bool>(n + 2, false));
        return build(1, n);
    }
private:
    vector<vector<vector<TreeNode*>>> memo;
    vector<vector<bool>> done;
    vector<TreeNode*> build(int lo, int hi) {
        if (lo > hi) return {nullptr};
        if (done[lo][hi]) return memo[lo][hi];
        vector<TreeNode*> res;
        for (int i = lo; i <= hi; i++) {
            vector<TreeNode*> lefts = build(lo, i - 1);
            vector<TreeNode*> rights = build(i + 1, hi);
            for (TreeNode* l : lefts) {
                for (TreeNode* r : rights) {
                    res.push_back(new TreeNode(i, l, r));
                }
            }
        }
        done[lo][hi] = true;
        return memo[lo][hi] = res;
    }
};