class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto ele:nums){
            minHeap.push(ele);
            if(minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) minHeap.pop();

        return minHeap.top();
    }
};
