class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> umap(nums.begin(), nums.end());        
        int longest = 0;

        for(int n:umap){
            if(umap.find(n-1)==umap.end()){
                int length = 1;

                while(umap.find(n+length)!=umap.end()){
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
