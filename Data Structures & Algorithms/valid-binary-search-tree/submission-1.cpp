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
    void getInorder(TreeNode* root, vector<int> &check){
        if(!root) return;

        getInorder(root->left, check);
        check.push_back(root->val);
        getInorder(root->right, check);

        return;
    }

    bool isValidBST(TreeNode* root) {
        vector<int> check;

        getInorder(root, check);

        for(int i=0; i<check.size()-1; i++){
            if(check[i] >= check[i+1]) return false;
        }

        return true;
    }
};
