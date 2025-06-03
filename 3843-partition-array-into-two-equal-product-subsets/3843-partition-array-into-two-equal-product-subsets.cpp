class Solution {
public:
    bool solve(int i, vector<int>& nums, long long target, long long prod){
        int n = nums.size();
        if(i >=n || prod > target) return false;
        if(prod == target) return true;
        return solve(i+1, nums, target, prod*nums[i]) || solve(i+1, nums, target, prod);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 totalProd = 1;
        for (int num : nums) {
            totalProd *= num;
        }

        __int128 targetSquared = (__int128)target * target;

        if (totalProd != targetSquared) return false;
        return solve(0, nums, target, 1);
    }
};