class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(m, INT_MIN)));
        return solve(0, 0, m-1, dp, grid);
    }

    int solve(int row, int col1, int col2, vector<vector<vector<int>>>&dp, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return INT_MIN;
        if(row == grid.size() - 1){
            if(col1 == col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }

        if(dp[row][col1][col2] != INT_MIN) return dp[row][col1][col2];

        int ans = INT_MIN;

        for(int d1 = -1; d1 <= 1; d1++){
            for(int d2 = -1; d2 <= 1; d2++){
                int curr;
                if(col1 == col2) curr = grid[row][col1];
                else curr = grid[row][col1] + grid[row][col2];

                curr += solve(row+1, col1+d1, col2+d2, dp, grid);
                ans = max(ans, curr);
            }
        }
        return dp[row][col1][col2] = ans;
    }
};