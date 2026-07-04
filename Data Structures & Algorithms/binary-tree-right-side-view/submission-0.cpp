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
    void getRSW(TreeNode* root, vector<int> &store, int level){
        if(root == nullptr) return;

        if(level == store.size()) store.push_back(root->val);

        getRSW(root->right, store, level+1);
        getRSW(root->left, store, level+1);
        
        return;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        getRSW(root, ans, 0);

        return ans;
    }
};
