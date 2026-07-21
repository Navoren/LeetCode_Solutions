class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, dp, grid);
    }

    int solve(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if(row < 0 || col < 0) return 1e9;
        if(row ==0 && col == 0) return grid[0][0];

        if(dp[row][col] != -1) return dp[row][col];

        int up = solve(row - 1, col, dp, grid);
        int left = solve(row, col-1, dp, grid);

        return dp[row][col] = grid[row][col] + min(up, left);
    }
};