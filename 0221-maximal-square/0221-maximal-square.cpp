class Solution {
public:
int n, m;
int maxi = 0;
    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                solve(i,j,matrix, dp);
            }
        }

        return maxi*maxi;
    }

    int solve(int i, int j, vector<vector<char>>&matrix, vector<vector<int>>&dp){
        if( i>= n || j >= m)return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(i+1, j, matrix, dp);
        int right = solve(i, j+1, matrix, dp);
        int diagonal = solve(i+1, j+1, matrix, dp);

        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min({down , right, diagonal});
            maxi = max(maxi, dp[i][j]);
        }else{
           dp[i][j] = 0;
        }

        return dp[i][j];
    }
};