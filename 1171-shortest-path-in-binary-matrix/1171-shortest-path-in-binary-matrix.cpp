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

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        q.push({1, {0, 0}});

        int delrow[] = {0, 1, -1, 0, 1, -1, 1, -1};
        int delcol[] = {1, 0, 0, -1, 1, 1, -1, -1};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i = 0; i < 8; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = dis + 1;
                    if(nrow == n - 1 && ncol == m - 1) return dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};
