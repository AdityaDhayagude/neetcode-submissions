class Solution {
public:
    void findCombinationSum(int idx, vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = idx; i<nums.size(); i++){
            if(i>idx && nums[i] == nums[i-1]) continue;

            if(nums[i] > target) break;
            ds.push_back(nums[i]);
            findCombinationSum(i+1, nums,target-nums[i], ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds; 

        findCombinationSum(0, candidates,target, ans, ds);

        return ans;
    }
};
