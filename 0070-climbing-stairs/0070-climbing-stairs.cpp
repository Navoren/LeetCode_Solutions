class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }

    int solve(int n, vector<int>& dp){
        if( n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int pick1 = solve(n-1, dp);
        int pick2 = solve(n-2, dp);

        return dp[n] = pick1 + pick2;
    }
};