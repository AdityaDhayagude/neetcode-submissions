class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> groups;

        for(string s:strs){
            string label = s;

            sort(label.begin(), label.end());

            groups[label].push_back(s);
        }

        for(auto &pair:groups){
            ans.push_back(pair.second);
        }

        return ans;
    }
};
