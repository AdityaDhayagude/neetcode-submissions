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
    int dfs(TreeNode* root, int &maxTotal){
        if(!root) return 0;

        int leftGain = max(0, dfs(root->left, maxTotal));
        int rightGain = max(0, dfs(root->right, maxTotal));

        maxTotal = max(maxTotal, leftGain + root->val + rightGain);

        return root->val + max(leftGain, rightGain);

    }

    int maxPathSum(TreeNode* root) {
        int maxTotal = INT_MIN;
        
        dfs(root, maxTotal);

        return maxTotal;
    }
};
