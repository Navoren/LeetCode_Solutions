class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int total = 0;
        for (int x : nums) total += x;

        int left = 0;
        for (int i = 0; i < n; i++) {
            total -= nums[i];
            ans[i] = abs(left - total);
            left += nums[i];
        }

        return ans;
    }
};