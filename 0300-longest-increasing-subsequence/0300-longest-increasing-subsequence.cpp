class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n,0,-1, nums, dp);
    }

    int solve(int n, int i, int prev, vector<int>&nums, vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int notPick = solve(n,i+1, prev, nums, dp);

        int pick = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            pick = 1 + solve(n,i+1, i, nums, dp);
        }

        return dp[i][prev+1] = max(pick,notPick);
    }
};