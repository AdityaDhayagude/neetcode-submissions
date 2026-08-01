class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> maxHeap;

        for(auto ele: nums){
            maxHeap.push(ele);
        }
        
        int count = 0;

        while(count!=k-1){
            maxHeap.pop();
            count++;
        }

        return maxHeap.top();
    }
};
