class Solution {
public:
    const int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        int total = 0;
        vector<int> dp(26);

        for(auto& c : s){
            c = c - 'a';
            int add = (total - dp[c] + MOD) % MOD;
            dp[c] = 1 + total;
            total = (dp[c] + add) % MOD;
        }

        return total;
    }
};