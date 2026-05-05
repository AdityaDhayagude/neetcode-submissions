class Solution {
public:
    bool isPalindrome(string s) {
        
        string converted = "";


        for(char c:s){
            if(isalnum(c)){
                converted += tolower(c);
            }
        }

        int n = converted.length();

        for(int i=0;i<n/2; i++){
            if(converted[i]!=converted[n-i-1]) return false;
        }

        return true;

    }
};
