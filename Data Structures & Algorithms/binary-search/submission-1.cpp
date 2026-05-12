class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        if(target == nums[0]) return 0;
        if(target > nums[right]) return -1;

        while(left<right){
            int mid = right+left/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
        }

        return -1;
    }
};
