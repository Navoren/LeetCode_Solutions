class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(dp, cost, n-1), solve(dp, cost, n-2));
    }

    int solve(vector<int> &dp, vector<int>&cost, int i){
        if(i == 0) return cost[0];
        if(i == 1) return cost[1];

        if(dp[i] != -1) return dp[i];

        int oneStep = solve(dp, cost, i-1);
        int twoStep = solve(dp, cost, i-2);
        return dp[i] = cost[i] + min(oneStep, twoStep);
    }
};