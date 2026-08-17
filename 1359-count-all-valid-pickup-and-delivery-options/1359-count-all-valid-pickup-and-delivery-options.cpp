class Solution {
public:
    const int MOD = 1e9 + 7;

    long long solve(int p, int d, vector<vector<long long>>& dp) {
        if (p == 0 && d == 0) return 1;

        if (dp[p][d] != -1) return dp[p][d];

        long long ans = 0;

        if (p > 0) {
            ans += p * solve(p - 1, d, dp);
        }

        if (d > p) {
            ans += (d - p) * solve(p, d - 1, dp);
        }

        return dp[p][d] = ans % MOD;
    }

    int countOrders(int n) {
        vector<vector<long long>> dp(n + 1,vector<long long>(n + 1, -1));
        return solve(n, n, dp);
    }
};