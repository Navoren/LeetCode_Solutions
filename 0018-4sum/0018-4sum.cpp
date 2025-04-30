class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long target_2 = (long long)target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;

                while (left < right) {
                    int two_sum = nums[left] + nums[right];
                    if (two_sum < target_2) {
                        ++left;
                    } else if (two_sum > target_2) {
                        --right;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == res.back()[2]) ++left;
                        while (left < right && nums[right] == res.back()[3]) --right;
                    }
                }
            }
        }
        return res;
    }
};
