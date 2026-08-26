class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(target > total) return 0;
        vector<vector<int>> dp(n, vector<int>(2*total+1, INT_MIN));
        return solve(0, 0, target, nums, dp, total);
    }

    int solve(int i, int sum, int target, vector<int>&nums, vector<vector<int>>&dp, int offset){
        if(i == nums.size()) return sum == target ? 1 : 0;
        if(dp[i][sum + offset] != INT_MIN) return dp[i][sum + offset];
        
        int add = solve(i+1, sum + nums[i], target, nums, dp, offset);
        int sub = solve(i+1, sum - nums[i], target, nums, dp, offset);

        return dp[i][sum + offset] = add + sub;
    }
};