class Solution {
public:
    int countCommas(int n) {
        return max(0, n - 999)
             + max(0, n - 999999)
             + max(0, n - 999999999);
    }
};