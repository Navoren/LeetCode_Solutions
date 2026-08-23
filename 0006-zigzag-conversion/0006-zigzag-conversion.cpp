class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length()) return s;

        int idx = 0;
        int dir = 1;
        vector<vector<char>> rows(numRows);

        for(char c : s){
            rows[idx].push_back(c);
            if(idx == 0) dir = 1;
            else if(idx == numRows - 1) dir = -1;

            idx += dir;
        }

        string res;
        for(const auto& row : rows){
            for(char c : row){
                res += c;
            }
        }

        return res;
    }
};