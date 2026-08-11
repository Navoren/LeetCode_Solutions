class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]+1;
        int i = 1;
        while(i<n && nums[i] == nums[i-1] + 1) i++;

        int sum = accumulate(nums.begin(), nums.begin() + i, 0);

        unordered_set<int> s(nums.begin(), nums.end());

        while (s.count(sum)) {
            sum++;
        }
        return sum;
    }
};