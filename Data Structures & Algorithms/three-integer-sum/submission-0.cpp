class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Optimization: If the smallest number is > 0, sum can never be 0
            if (nums[i] > 0) break;

            // Step 4a: Skip duplicates for the "Fixed" number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Two pointers for the rest of the array
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Step 4b: Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Need a larger sum
                } 
                else {
                    right--; // Need a smaller sum
                }
            }
        }
        return result;
    }
};
