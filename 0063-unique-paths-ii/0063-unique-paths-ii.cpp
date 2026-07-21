class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, dp, obstacleGrid);
    }

    int solve(int row, int col, vector<vector<int>>&dp, vector<vector<int>>& arr){
        if (row < 0 || col < 0) return 0;
        if (arr[row][col] == 1) return 0;
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];

        int up = solve(row-1, col , dp, arr);
        int down = solve(row, col-1, dp, arr);

        return dp[row][col] = up + down;
    }
};