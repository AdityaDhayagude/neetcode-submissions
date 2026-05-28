class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currPrice = 0;
        int maxPrice = 0;
        int i = 0;

        for(int j=1; j<prices.size(); j++){
            if(prices[j]<=prices[i]) i=j;

            currPrice = prices[j]-prices[i];
            maxPrice = max(maxPrice, currPrice);
        }

        return maxPrice;
    }
};
