class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

    for(int ele : stones)
        maxHeap.push(ele);

    while(maxHeap.size() > 1){
        int x = maxHeap.top(); maxHeap.pop();  // largest
        int y = maxHeap.top(); maxHeap.pop();  // second largest

        if(x != y) maxHeap.push(x - y);       // push remainder
    }

    return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
