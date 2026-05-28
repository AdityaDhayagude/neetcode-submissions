class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);

        if (s1.length() > s2.length()) return false;

        for(int i=0; i<s1.length();i++){
            s1Count[s1[i]-'a']++;
            windowCount[s2[i]-'a']++;
        }

        if(s1Count == windowCount) return true;

        for(int j = s1.length(); j<s2.length(); j++){
            windowCount[s2[j]-'a']++;

            int leftIdx = j-s1.length();
            windowCount[s2[leftIdx] - 'a']--;

            if(s1Count == windowCount) return true;
        }   

        return false;
    }
};
