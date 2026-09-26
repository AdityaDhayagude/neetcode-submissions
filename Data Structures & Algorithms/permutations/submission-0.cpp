class Solution {
public:
    void recurPermute(vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, vector<bool> &freq){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = true;
                recurPermute(ans, ds, nums, freq);
                freq[i] = false;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(nums.size(), false);

        recurPermute(ans, ds, nums, freq);

        return ans;
    }
};
