class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};

        int dir = 0;
        int row = 0, col = 0;

        for (int i = 0; i < m * n; i++) {
            ans.push_back(matrix[row][col]);
            vis[row][col] = true;

            int newRow = row + delRow[dir];
            int newCol = col + delCol[dir];

            if (newRow < 0 || newRow >= m ||
                newCol < 0 || newCol >= n ||
                vis[newRow][newCol]) {

                dir = (dir + 1) % 4;
                newRow = row + delRow[dir];
                newCol = col + delCol[dir];
            }

            row = newRow;
            col = newCol;
        }

        return ans;
    }
};