class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int, int> umap;

        for(int i=0; i<nums.size();i++){
            umap[nums[i]]++;;
        }

        for (auto i = umap.begin(); i != umap.end(); i++){
            if(i->second>1) return true;
        }

        return false;
    }
};