class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<int> dp(n, -1);
        return solve(0, pressedKeys, dp);
    }

    int solve(int ind, string& s, vector<int>&dp){
        if(ind == s.size()) return 1;
        if(dp[ind] != -1) return dp[ind];

        long long ans = 0;
        int limit = (s[ind] == '7' || s[ind] == '9') ? 4 : 3;

        for(int i = ind; i < min(ind + limit, (int)s.size()); i++){
            if(s[ind] != s[i]) break;
            ans = (ans + solve(i+1, s, dp)) % MOD;
        }

        return dp[ind] = ans;
    }
};