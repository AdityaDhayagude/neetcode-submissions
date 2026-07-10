class PrefixTree {
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;

        TrieNode(){
            for(int i=0; i<26; i++) 
                children[i] = nullptr;
            isEnd = false;
        }
    };

    TrieNode* root;

public:


    PrefixTree() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(char c:word){
            int idx = c-'a';

            if(!curr->children[idx]) curr->children[idx] = new TrieNode();

            curr = curr->children[idx];

        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for(char c : word){
            int idx = c - 'a';
            if(!curr->children[idx]) return false;
            curr = curr->children[idx];
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(char c : prefix){
            int idx = c - 'a';

            if(!curr->children[idx]) return false;
            curr = curr->children[idx];
        }

        return true;
    }
};
