class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(board[i][j] == 'O'){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow>=0 && ncol >= 0 && nrow <n && ncol <m && vis[nrow][ncol] != 1 && board[nrow][ncol] == 'O'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};