class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() < 2) return arr.size();
        int maxLen = 1;
        int currLen = 1;
        char prevSign = '=';

        for(int i=1; i<arr.size(); i++){
            if(arr[i-1]>arr[i]){
                currLen = (prevSign == '>') ? currLen+1:2;
                prevSign = '<';
            }
            else if(arr[i-1]<arr[i]){
                currLen = (prevSign == '<') ? currLen+1:2;
                prevSign = '>';
            }
            else{
                currLen = 1;
                prevSign = '=';
            }

            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};