class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = INT_MIN;
        int left = 0;
        int right = heights.size()-1; 

        while(left<right){
            area = max(area, (right-left)*min(heights[left], heights[right]));

            if(heights[left]<heights[right]) left++;
            else if(heights[left]>heights[right]){
                right --;
            }
            else{
                left++;
            }
        }

        return area;
    }
};
