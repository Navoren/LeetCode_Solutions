class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int total = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if(total < desiredTotal) return false;
        if(desiredTotal <= maxChoosableInteger) return true;
        int totalMasks = 1 << maxChoosableInteger;
        vector<int> dp(totalMasks, -1);
        return solve(0, maxChoosableInteger, desiredTotal, dp);
    }

    bool solve(int mask, int maxChoosableInteger, int desiredTotal, vector<int>&dp){
        if(dp[mask] != -1 ) return dp[mask];
        for(int i= 1; i<= maxChoosableInteger; i++){
            int bit = 1 << (i - 1);

            if(mask & bit) continue;

            if(i >= desiredTotal) return dp[mask] = true;
            int newMask = mask | bit;
            if(!solve(newMask, maxChoosableInteger, desiredTotal - i, dp)){
                return dp[mask] = true;
            }
        }
        return dp[mask] = false;
    }
};