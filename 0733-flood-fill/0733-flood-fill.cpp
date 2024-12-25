class Solution {
private:
void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int ini){
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = newColor;
    for(int delrow = -1; delrow <= 1; delrow++){
        for(int delcol = -1; delcol<= 1; delcol++){
            int nrow = row + delrow;
            int ncol = col + delcol;
            if((abs(delrow-delcol)==1) && nrow>=0 && ncol>=0 && nrow<n && ncol <m && image[nrow][ncol] == ini && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, ans, image, newColor, ini);
            }
        }
    }
}

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, color, initialColor);
        return ans;
    }
};