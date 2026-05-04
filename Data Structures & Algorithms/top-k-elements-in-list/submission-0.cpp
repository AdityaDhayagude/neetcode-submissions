class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int n : nums) counts[n]++;

        // Transfer map to a vector of pairs so we can sort by frequency
        // Pair: {frequency, number}
        vector<pair<int, int>> freqPairs;
        for (auto const& [val, freq] : counts) {
            freqPairs.push_back({freq, val});
        }

        // Sort by frequency in descending order
        sort(freqPairs.rbegin(), freqPairs.rend());

        // Take the first k numbers
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqPairs[i].second);
        }

        return result;
    }
};
