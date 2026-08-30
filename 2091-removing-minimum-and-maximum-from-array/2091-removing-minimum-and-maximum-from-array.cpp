class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minPos = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxPos = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minPos, maxPos);
        int right = max(minPos, maxPos);

        int fromLeft = right + 1;
        int fromRight = n - left;
        int fromBoth = left + 1 + n - right;

        int ans = min({fromLeft, fromRight, fromBoth});
        return ans;

    }
};