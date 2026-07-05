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
    int getHeight(TreeNode* root){
        if(root == nullptr) return 0;

        return 1+max(getHeight(root->left), getHeight(root->right));
    }

    void getDiameter(TreeNode* root, int &maxD){
        if(root == nullptr) return;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        maxD = max(maxD, leftHeight + rightHeight);

        getDiameter(root->left, maxD);
        getDiameter(root->right, maxD);

        return;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = INT_MIN;

        getDiameter(root, maxD);

        return maxD;
    }
};
