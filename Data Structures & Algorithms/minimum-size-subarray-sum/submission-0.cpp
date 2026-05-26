class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        // int j = 0; 

        int minLength = INT_MAX;
        int currSum = 0;

        for(int j=0; j<nums.size(); j++){
            currSum += nums[j];

            while(currSum >= target){
                minLength = min(minLength, j-i+1);

                currSum -= nums[i];
                i++;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};