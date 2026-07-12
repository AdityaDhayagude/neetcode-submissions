class Solution {
struct TrieNode {        // ✅ class level
        TrieNode* children[26];
        string word;
        TrieNode(){
            for(int i=0; i<26; i++) children[i] = nullptr;
            word = "";
        }
    };

    void dfs(vector<vector<char>>& board, int r, int c,    // ✅ class level
             TrieNode* node, vector<string>& result){
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size()) return;
        if(board[r][c] == '#') return;

        char ch = board[r][c];
        int idx = ch - 'a';

        if(!node->children[idx]) return;
        TrieNode* next = node->children[idx];

        if(next->word != ""){
            result.push_back(next->word);
            next->word = "";
        }

        board[r][c] = '#';
        dfs(board, r+1, c, next, result);
        dfs(board, r-1, c, next, result);
        dfs(board, r, c+1, next, result);
        dfs(board, r, c-1, next, result);
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string& w : words){
            TrieNode* curr = root;
            for(char c : w){
                int idx = c - 'a';
                if(!curr->children[idx]) curr->children[idx] = new TrieNode();
                curr = curr->children[idx];
            }
            curr->word = w;
        }

        vector<string> result;
        for(int r = 0; r < board.size(); r++)
            for(int c = 0; c < board[0].size(); c++)
                dfs(board, r, c, root, result);


        return result;
    }
};
