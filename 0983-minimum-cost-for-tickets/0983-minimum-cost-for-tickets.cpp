class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(0, days, costs, dp);
    }

    int solve(int si, vector<int>& days, vector<int>& cost, vector<int>& dp) {
        int n = days.size();

        if (si >= n) return 0;

        if (dp[si] != -1) return dp[si];

        int costDay = cost[0] + solve(si + 1, days, cost, dp);

        int i = si;
        while (i < n && days[i] < days[si] + 7)
            i++;
        int costWeek = cost[1] + solve(i, days, cost, dp);

        i = si;
        while (i < n && days[i] < days[si] + 30)
            i++;
        int costMonth = cost[2] + solve(i, days, cost, dp);

        return dp[si] = min({costDay, costWeek, costMonth});
    }
};