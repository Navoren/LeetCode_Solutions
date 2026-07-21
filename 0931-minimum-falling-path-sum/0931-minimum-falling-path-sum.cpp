class Solution {
public:
    const int INF = 1e9;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n, INF));
        int ans = 1e9;
        for(int i=0; i<n; i++){
            ans = min(ans, solve(n-1, i, dp, matrix));
        }

        return ans;
    }

    int solve(int row, int col, vector<vector<int>>&dp, vector<vector<int>>& matrix){
        int n = matrix.size();
        if(col < 0 || col >= n) return 1e9;
        if(row == 0) return matrix[0][col];
        if(dp[row][col] != INF) return dp[row][col];

        int down = solve(row-1, col, dp, matrix);
        int leftDiag = solve(row-1, col-1, dp, matrix);
        int rightDiag = solve(row-1, col+1, dp, matrix);

        return dp[row][col] = matrix[row][col] + min(down, min(leftDiag, rightDiag));
    }
};