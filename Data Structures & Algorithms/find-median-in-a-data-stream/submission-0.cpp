class MedianFinder {
    // Small Heap (MaxHeap)
    priority_queue<int> maxHeap;

    //Large Heap(MinHeap)
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}
    
    void addNum(int num) {
         // push to correct side first!
        if(!maxHeap.empty() && num > maxHeap.top())
            minHeap.push(num);
        else
            maxHeap.push(num);

        // rebalance
        if((int)maxHeap.size() - (int)minHeap.size() > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if((int)minHeap.size() - (int)maxHeap.size() > 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int sizeSum = maxHeap.size() + minHeap.size();

        if(sizeSum % 2 == 0){
            return (maxHeap.top() + minHeap.top())/2.0;
        }else{
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
};
