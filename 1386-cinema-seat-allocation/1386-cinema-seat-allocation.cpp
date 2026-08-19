class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << (col - 1));
        }

        int ans = (n - rows.size()) * 2;

        int LEFT =
            (1 << 1) |
            (1 << 2) |
            (1 << 3) |
            (1 << 4);

        int MIDDLE =
            (1 << 3) |
            (1 << 4) |
            (1 << 5) |
            (1 << 6);

        int RIGHT =
            (1 << 5) |
            (1 << 6) |
            (1 << 7) |
            (1 << 8);

        for (auto& [row, mask] : rows) {

            bool leftFree   = !(mask & LEFT);
            bool middleFree = !(mask & MIDDLE);
            bool rightFree  = !(mask & RIGHT);

            if (leftFree && rightFree) {
                ans += 2;
            }
            else if (leftFree || middleFree || rightFree) {
                ans += 1;
            }
        }

        return ans;
    }
};