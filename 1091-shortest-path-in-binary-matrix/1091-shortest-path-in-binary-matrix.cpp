class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) {
            return -1;
        }
        if(n == 1 && m == 1 && grid[0][0] == 0) {
            return 1;
        }

        queue<tuple<int,int,int>> q; // {dist, row, col}
        q.push({1,0,0});

        int delrow[] = {0, 1, -1, 0, 1, -1, 1, -1};
        int delcol[] = {1, 0, 0, -1, 1, 1, -1, -1};

        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        dist[0][0] = 1;
        while(!q.empty()){
            auto it = q.front();
            int dis = get<0>(it);
            int row = get<1>(it);
            int col = get<2>(it);
            q.pop();

            for(int i=0; i<8; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = dis + 1;
                    if(nrow == n - 1 && ncol == m - 1) return dis + 1;
                    q.push({dis + 1, nrow, ncol});
                }
            }
        }
        return -1;
    }
};