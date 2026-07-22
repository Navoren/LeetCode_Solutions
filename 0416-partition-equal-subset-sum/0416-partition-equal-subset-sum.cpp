class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(auto it : nums){
            totalSum += it;
        }

        if(totalSum % 2) return false;

        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(0, nums, target, dp);
    }

    bool solve(int ind, vector<int>& arr, int sum, vector<vector<int>>&dp){
        if(sum == 0) return true;
        if(ind == arr.size()) return false;
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        bool notPick = solve(ind+1, arr, sum, dp);
        bool pick = false;
        if(arr[ind] <= sum){
            pick = solve(ind+1, arr, sum - arr[ind], dp);
        }
        
        return dp[ind][sum] = pick || notPick;
        
    }
};