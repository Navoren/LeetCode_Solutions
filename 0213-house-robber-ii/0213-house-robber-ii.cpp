class Solution {
    int maxNonAdj(int start, int end, vector<int>& nums, vector<int>& dp) {
        if (start > end) return 0;
        if (dp[start] != -1) return dp[start];

        int pick = nums[start] + maxNonAdj(start + 2, end, nums, dp);
        int nopick = maxNonAdj(start + 1, end, nums, dp);

        return dp[start] = max(pick, nopick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int ans1 = maxNonAdj(0, n - 2, nums, dp1);
        int ans2 = maxNonAdj(1, n - 1, nums, dp2);

        return max(ans1, ans2);
    }
};
