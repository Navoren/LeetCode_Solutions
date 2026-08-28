class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for(int it : prices){
            if(it < buy){
                buy = it;
            }else if( it - buy > profit){
                profit = it - buy;
            }
        }
        return profit;
    }
};