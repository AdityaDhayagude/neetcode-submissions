class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> uset;

        for(int i=0; i<nums.size(); i++){
            if(uset.find(nums[i])!=uset.end()) return nums[i];
            uset.insert(nums[i]);
        }

        return -1;
    }
};
