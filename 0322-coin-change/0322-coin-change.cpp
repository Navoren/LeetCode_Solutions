class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        int ans = solve(amount, coins, dp);
        return ans == INT_MAX ? -1 : ans;
    }

    int solve(int target, vector<int>&coins, vector<int>&dp){
        if(target == 0) return 0;
        if(target < 0) return INT_MAX;
        if(dp[target] != -1) return dp[target];

        int ans = INT_MAX;
        for(int coin : coins){
            int res = solve(target - coin, coins, dp);
            if(res != INT_MAX) ans = min(ans, 1 + res);
        }
        return dp[target] = ans;
    }
};