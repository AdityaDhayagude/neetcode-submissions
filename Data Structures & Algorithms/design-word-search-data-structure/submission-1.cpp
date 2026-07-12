class WordDictionary {
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;

        TrieNode(){
            for(int i = 0; i<26; i++)
                children[i] = nullptr;
            isEnd = false;
            
        }
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    bool dfs(TrieNode* node, string& word, int i){
    if(i == word.size()) return node->isEnd;

    char c = word[i];

    if(c == '.'){
        // try ALL 26 children!
        for(int j = 0; j < 26; j++){
            if(node->children[j] && dfs(node->children[j], word, i+1))
                return true;
        }
        return false;
    } else {
        int idx = c - 'a';
        if(!node->children[idx]) return false;
        return dfs(node->children[idx], word, i+1);
    }
}
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            int idx = c - 'a';

            if(!curr->children[idx]) curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
