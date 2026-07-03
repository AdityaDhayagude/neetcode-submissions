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
    TreeNode* build(vector<int> &preorder, int preS, int preE, vector<int> &inorder, int inS, int inE, unordered_map<int, int> &mp){

        //Base condition
        if(preS > preE || inS > inE) return nullptr;

        // Making the new node with the preS for obvious reasons 
        TreeNode* root = new TreeNode(preorder[preS]);

        //Getting the mid value which is basically start of the point in inorder where the 
        //pre start is located 

        int mid = mp[preorder[preS]];  //Now you know why the map was made in order to not make the code run a lot of times
        int leftSize = mid - inS; //how many nodes in left subtree

        root->left = build(preorder, preS+1, preS+leftSize, inorder, inS, mid-1, mp);
        
        root->right = build(preorder, preS+leftSize+1, preE, inorder, mid+1, inE, mp);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for(int i =0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};
