class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 , -1));
        return solve(0,1, prices, dp);
    }

    int solve(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(i == prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        int profit=0;

        if(buy){
            int take = -prices[i] + solve(i+1, 0, prices, dp);
            int notTake = solve(i+1, 1, prices, dp);
            profit = max(take, notTake);
        }else{
            int sell = prices[i] + solve(i+1, 1, prices, dp);
            int notSell = solve(i+1, 0, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[i][buy] = profit;
    }
};