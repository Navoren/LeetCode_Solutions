class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nextBuy = 0;
        int nextSell = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {
            int currBuy = max(
                -prices[i] + nextSell,
                nextBuy                 
            );

            int currSell = max(
                prices[i] + nextBuy,    
                nextSell                
            );

            nextBuy = currBuy;
            nextSell = currSell;
        }

        return nextBuy;
    }
};