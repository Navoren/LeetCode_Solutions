class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int,int>> dq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        dq.push_front({0,0});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!dq.empty()){
            auto [row, col] = dq.front();
            dq.pop_front();

            for(int i=0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow < 0 || ncol < 0 || nrow >= m || ncol >= n) continue;

                int newCost = dist[row][col] + grid[nrow][ncol];

                if(newCost < dist[nrow][ncol]){
                    dist[nrow][ncol] = newCost;

                    if(grid[nrow][ncol] == 0) dq.push_front({nrow, ncol});
                    else dq.push_back({nrow, ncol});
                }
            }
        }

        return dist[m-1][n-1] < health;
    }
};