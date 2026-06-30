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
    int HeightOfTree(TreeNode* root){
        if(root == nullptr) return 0;

        return 1+max(HeightOfTree(root->left), HeightOfTree(root->right));

    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int leftHeight = HeightOfTree(root->left);
        int rightHeight = HeightOfTree(root->right);

        int balanced = abs(leftHeight - rightHeight) <=1;

        return balanced && isBalanced(root->left) && isBalanced(root->right);
    }
};
