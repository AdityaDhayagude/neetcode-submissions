class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int maxLen = INT_MIN;
        unordered_set<char> uset;

        for(int j=0;j<s.length(); j++){
            while (uset.find(s[j]) != uset.end()) {
                uset.erase(s[i]); // Remove the leftmost character from our set
                i++;              // Move left pointer forward
            }

            uset.insert(s[j]);
            maxLen = max(maxLen, j-i+1);
        }

        return (maxLen==INT_MIN) ? 0:maxLen;
    }
};
