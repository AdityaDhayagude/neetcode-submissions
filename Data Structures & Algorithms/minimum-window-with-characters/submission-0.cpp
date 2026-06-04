class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tCount(126, 0);
        vector<int> windowCount(126, 0);
        int requiredMatches = 0;

        for(char c : t) tCount[c]++;

        for(int c:tCount){
            if(c>0) requiredMatches++;
        }

        int i = 0;
        int currentMatches = 0;
        int minLength = INT_MAX;
        int startIdx = -1;

        for(int j = 0; j< s.length(); j++){
            char rightChar = s[j];
            windowCount[rightChar]++;

            if(tCount[rightChar]>0 && windowCount[rightChar] == tCount[rightChar]){
                currentMatches++;
            }

            while(currentMatches == requiredMatches){
                if(j-i+1<minLength){
                    minLength = j-i+1;
                    startIdx = i;
                }
                char leftChar = s[i];
                windowCount[leftChar]--;

                if(tCount[leftChar]>0 && windowCount[leftChar] < tCount[leftChar]) currentMatches--;

                i++;
            }
        }

        return(startIdx == -1) ? "":s.substr(startIdx, minLength);
    }
};
