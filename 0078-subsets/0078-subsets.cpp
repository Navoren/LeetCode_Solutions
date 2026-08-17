class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalMasks = 1 << n;
        vector<vector<int>> dp(totalMasks);

        for(int i=0; i< totalMasks; i++){
            ans.push_back(solve(i, nums, dp));
        }
        return ans;
    }

    vector<int> solve(int mask , vector<int>&nums, vector<vector<int>>& dp){
        if(mask == 0) return {};

        if(!dp[mask].empty()) return dp[mask];

        int bit = __builtin_ctz(mask);
        int prevMask = mask & (mask - 1);

        dp[mask] = solve(prevMask, nums, dp);
        dp[mask].push_back(nums[bit]);
        return dp[mask];
    }
};