class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        
        int currSum = 0;
        int ans = 0;

        int targetSum = k*threshold;

        for(int i=0; i<nums.size(); i++){
            
            currSum += nums[i];

            if(i>=k-1){
                if(currSum >= targetSum) ans++;
            

            currSum -= nums[i-k+1];
            }
        }

        return ans;
    }
};