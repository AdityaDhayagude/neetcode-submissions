class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> umap1, umap2;

        if(s.length()!=t.length()) return false;

        for(int i=0; i<s.length(); i++){
            umap1[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            umap2[t[i]]++;
        }

        for(auto c:s){
            if(umap1[c]!=umap2[c]) return false;
        }

        return true;
    }
};
