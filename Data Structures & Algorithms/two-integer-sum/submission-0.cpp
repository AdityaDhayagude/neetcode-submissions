class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            int missing = target - nums[i];

            // Check if the complement exists in our map
            if (umap.find(missing) != umap.end()) {
                // Found it! Return the index of the missing number and current index
                return {umap[missing], i};
            }

            // If not found, add current number and its index to the map
            umap[nums[i]] = i;
        }

        // Return empty if no solution is found (though the problem usually guarantees one)
        return {};
    }
};
