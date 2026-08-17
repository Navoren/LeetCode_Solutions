class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> masks;
        for(string s : arr){
            int mask = 0;
            bool valid = true;
            for(char c : s){
                int bit = c - 'a';

                if(mask & ( 1 << bit)){
                    valid = false;
                    break;
                }

                mask |= (1 << bit);
            }

            if(valid) masks.push_back(mask);
        }

        int n = masks.size();
        vector<unordered_map<int, int>> dp(n);
        return solve(0, masks, 0, dp);
    }

    int solve(int ind, vector<int>&masks, int currMask, vector<unordered_map<int, int>> &dp){
        if(ind == masks.size()) return 0;

        if(dp[ind].count(currMask)) return dp[ind][currMask];

        int ans = solve(ind +1, masks, currMask, dp);

        if((currMask & masks[ind]) == 0){
            int newMask = currMask | masks[ind];
            int len = __builtin_popcount(masks[ind]);
            ans = max(ans, len + solve(ind+1, masks, newMask, dp));
        }

        return dp[ind][currMask] = ans;
    }
};