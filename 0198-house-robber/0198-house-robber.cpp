class Solution {
public:
    int maxNonAdj(int n, vector<int>& nums, vector<int>&dp){
        if(n  == 0){
            dp[n] = nums[0];
            return nums[0];
        }
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        int pick = nums[n] + maxNonAdj(n-2, nums, dp);
        int nopick = 0 + maxNonAdj(n-1, nums, dp);

        dp[n] = max(pick, nopick);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = maxNonAdj(n-1, nums, dp);
        return ans;
    }
};