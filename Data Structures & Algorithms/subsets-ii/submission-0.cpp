class Solution {
public:
    void getSubsets(int idx, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums){
        ans.push_back(ds);

        for(int i = idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            getSubsets(i+1, ans, ds, nums);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds{};

        getSubsets(0, ans, ds, nums);

        return ans;
    }
};
