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

class Codec {
public:

    //SERIALIZE

    void dfs(TreeNode* root, string &result){
        if(!root){
            result += "N,";
            return;
        }

        result += to_string(root->val) + ",";

        dfs(root->left, result);
        dfs(root->right, result);

        // return result;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        dfs(root, result);
        return result;
    }

    //DESERIALIZE

    TreeNode* build(queue<string> &tokens){
        string token = tokens.front();
        tokens.pop();

        if(token == "N") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));

        node->left = build(tokens);
        node->right = build(tokens);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue <string> tokens;
        stringstream ss(data);

        string token;

        while(getline(ss, token, ',')){
            tokens.push(token);
        }

        return build(tokens);
    }
};
