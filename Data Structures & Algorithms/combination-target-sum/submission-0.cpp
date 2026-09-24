class Solution {
public:
    void getCombinationSum(int idx, vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &ds){
        if(idx == nums.size()){
            if(target == 0){
                ans.push_back(ds);
            }

            return;
        }

        if(nums[idx] <= target){
            ds.push_back(nums[idx]);
            getCombinationSum(idx, nums, target-nums[idx], ans, ds);
            ds.pop_back();
        }

        getCombinationSum(idx+1, nums, target, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        getCombinationSum(0, nums, target, ans, ds);

        return ans;
    }
};
