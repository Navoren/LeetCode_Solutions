class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, dp, word1, word2);
    }

    int solve(int i, int j, vector<vector<int>>&dp, string word1, string word2){
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = solve(i+1, j+1, dp, word1, word2);

        int insertOp = solve(i, j+1, dp, word1, word2);
        int deleteOp = solve(i+1, j, dp, word1, word2);
        int replaceOp = solve(i+1, j+1, dp, word1, word2);

        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }
};