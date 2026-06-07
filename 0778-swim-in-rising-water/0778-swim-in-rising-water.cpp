class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int row = cur[1];
            int col = cur[2];

            if(row == n-1 && col == n-1)
                return cost;

            for(int i=0; i<4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 && ncol>=0 &&
                   nrow<n && ncol<n) {

                    int newCost =
                        max(cost, grid[nrow][ncol]);

                    if(newCost < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newCost;
                        pq.push({newCost, nrow, ncol});
                    }
                }
            }
        }

        return -1;
    }
};