class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding = 0, maxSum = 0;
        int minEnding = 0, minSum = 0;

        for (int x : nums) {
            maxEnding = max(x, maxEnding + x);
            maxSum = max(maxSum, maxEnding);

            minEnding = min(x, minEnding + x);
            minSum = min(minSum, minEnding);
        }

        return max(maxSum, -minSum);
    }
};