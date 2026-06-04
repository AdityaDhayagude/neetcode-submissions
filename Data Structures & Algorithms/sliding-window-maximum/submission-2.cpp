class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()<k) return {};
        if(k==1) return nums;

        vector<int> ans;
        deque<int> dq;
        int i=0, j=0;

        // 1st part of the solution

        for(j; j<k; j++){
            while(!dq.empty() && nums[j]>nums[dq.back()]) dq.pop_back();
            dq.push_back(j);
        }

        ans.push_back(nums[dq.front()]);

        for(j=k; j<nums.size(); j++){
            if(!dq.empty() && dq.front()<=j-k) dq.pop_front();

            while(!dq.empty() && nums[j]>nums[dq.back()]) dq.pop_back();
            
            dq.push_back(j);

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
