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
    TreeNode* build(vector<int> &preorder,int preS, int preE, vector<int> &inorder, int inS,int inE, unordered_map<int, int> &umap){
        if(inS > inE || preS > preE ) return nullptr;

        TreeNode* root = new TreeNode(preorder[preS]);

        int mid = umap[preorder[preS]];
        int leftSize = mid - inS;

        root->left = build(preorder, preS+1, preS+leftSize, inorder, inS, mid-1, umap);

        root->right = build(preorder, preS+leftSize+1, preE,inorder, mid+1, inE,  umap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> umap; 

        for(int i = 0; i<inorder.size(); i++){
            umap[inorder[i]] = i; 
        }

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size(), umap);
    }
};
