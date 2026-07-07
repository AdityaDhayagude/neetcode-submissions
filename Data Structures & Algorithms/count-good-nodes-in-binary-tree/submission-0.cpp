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
    int dfs(TreeNode* root, int maxSoFar, int &count){
    // base case?
    if(!root) return 0;
    // is current node good?
    if(root->val >= maxSoFar) count++;
    // recurse left and right, passing updated max
    dfs(root->left,  max(maxSoFar,root->val) , count);
    dfs(root->right,  max(maxSoFar,root->val) , count);

    // return count

    return count;
}

    int goodNodes(TreeNode* root) {
        int count = 0;
        return dfs(root, INT_MIN, count);
    }
};
