class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0; 
        int maxCount = 0;
        unordered_map<int, int> count;
        
        int i = 0; 

        for(int j=0; j<s.length(); j++){

            count[s[j]-'A']++;

            maxCount = max(maxCount, count[s[j]-'A']);

            while((j-i+1)-maxCount > k){
                count[s[i]-'A']--;
                i++;
            }

            maxLen = max(maxLen, j-i+1);
        }

        return maxLen;

    }
};
