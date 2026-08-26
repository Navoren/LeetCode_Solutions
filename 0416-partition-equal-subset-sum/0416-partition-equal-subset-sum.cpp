class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto it : nums){
            total += it;
        }

        vector<vector<int>> dp(n, vector<int>(total/2 + 1, -1));
        if(total%2 != 0) return false;
        else return solve(0, total/2, nums, dp);
    }

    bool solve(int i, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target == 0) return true;
        if(i == nums.size() || target < 0) return false;
        if(dp[i][target] != -1) return dp[i][target];

        bool notTake = solve(i+1, target, nums, dp);
        bool take = solve(i+1, target - nums[i], nums, dp);

        return dp[i][target] = take || notTake;
    }
};