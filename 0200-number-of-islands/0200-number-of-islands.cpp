class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( grid[i][j] == '1'){
                    count++;
                    dfs(i,j, grid);
                }
            }
        }
        return count;
    }

    void dfs(int i, int j, vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();

        grid[i][j] = '0';
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int k=0; k<4; k++){
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];

            if(nrow >=0 && ncol >=0 && nrow < n && ncol <m && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid);
            }
        }
    }
};