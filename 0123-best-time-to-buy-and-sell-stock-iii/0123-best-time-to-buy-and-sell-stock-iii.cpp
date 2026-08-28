class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2 , vector<int>(3, -1)));
        return solve(0,1,2, prices, dp);
    }

    int solve(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(i == prices.size() || cap == 0) return 0;

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        int profit=0;

        if(buy){
            int take = -prices[i] + solve(i+1, 0, cap, prices, dp);
            int notTake = solve(i+1, 1, cap, prices, dp);
            profit = max(take, notTake);
        }else{
            int sell = prices[i] + solve(i+1, 1, cap-1, prices, dp);
            int notSell = solve(i+1, 0, cap, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[i][buy][cap] = profit;
    }
};