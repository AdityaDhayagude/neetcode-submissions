class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uset;

        for(int i=0;i <nums.size();i++){
            if(uset.count(nums[i])) return true;

            uset.insert(nums[i]);

            if(uset.size()>k) uset.erase(nums[i-k]);
        }

        return false;
    }

    
};