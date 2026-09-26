class Solution {
public:
    void generateParenthesisHelper(int open, int close, vector<string> &ans, string &s){
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }

        if(open>0){
           string curr = s+'(';
           generateParenthesisHelper(open-1, close, ans, curr);
        }

        if(open < close){
            string curr = s + ')';
            generateParenthesisHelper(open, close-1, ans, curr);
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;

        generateParenthesisHelper(n, n, ans, s);

        return ans;
    }
};
