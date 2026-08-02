class Solution {
public:
    vector<int> memo;

    bool solve(int n) {
        if (n == 0)
            return false;

        if (memo[n] != -1)
            return memo[n];

        for (int i = 1; i * i <= n; i++) {
            if (!solve(n - i * i))
                return memo[n] = true;
        }

        return memo[n] = false;
    }

    bool winnerSquareGame(int n) {
        memo.assign(n + 1, -1);
        return solve(n);
    }
};