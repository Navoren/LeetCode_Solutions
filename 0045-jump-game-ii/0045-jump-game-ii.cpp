class Solution {
public:
const int INF = 1E9;
    int jump(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n, -1);
       return solve(0, nums, dp); 
    }

    int solve(int i, vector<int>&nums, vector<int>& dp){
        int n = nums.size();
        if(i >= n-1) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = INF;

        for(int jump = 1; jump <= nums[i]; jump++){
            if( i+ jump < n){
                ans = min(ans, 1 + solve(i+ jump, nums, dp));
            }
        }

        return dp[i] = ans;
    }
};