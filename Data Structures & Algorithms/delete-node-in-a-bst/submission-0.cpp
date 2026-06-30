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
    int Height(TreeNode* root){

        int x,y;
        if(root == NULL) return 0;
        
        x = Height(root->left);
        y = Height(root->right);

        return x>y ? x+1:y+1; 
    }

    TreeNode* InSucc(TreeNode* p){

        while(p && p->left!=NULL) p = p->left;

        return p;
    }

    TreeNode* InPre(TreeNode* p){

        while(p && p->right!=NULL) p = p->right;

        return p;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL){ return NULL;}

        TreeNode* p = root;
        TreeNode* q;

        if(p->val == key && p->left == nullptr && p->right == nullptr){
            if(p == root){
                return NULL;
            }
            delete(p);
            return nullptr;
        }

         if(p->val == key && p->left == nullptr){
        TreeNode* temp = p->right;
        delete p;
        return temp;
    }
    if(p->val == key && p->right == nullptr){
        TreeNode* temp = p->left;
        delete p;
        return temp;
    }

        if(key < p->val){
            p->left = deleteNode(p->left, key);
        }else if(key > p->val){
            p->right = deleteNode(p->right, key);
        }else{
            if(Height(p->left) > Height(p->right)){
                q = InPre(p->left);
                p->val = q->val;
                p->left = deleteNode(p->left, q->val);
            }else{
                q = InSucc(p->right);
                p->val = q->val;
                p->right = deleteNode(p->right, q->val);
            }
        }

        return p;
    }
};