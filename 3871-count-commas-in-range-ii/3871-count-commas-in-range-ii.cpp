class Solution {
public:
    long long countCommas(long long n) {
        return max(0LL, n - 999LL)
             + max(0LL, n - 999999LL)
             + max(0LL, n - 999999999LL)
             + max(0LL, n - 999999999999LL)
             + max(0LL, n - 999999999999999LL);
    }
};