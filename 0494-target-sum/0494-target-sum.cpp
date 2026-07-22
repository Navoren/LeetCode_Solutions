class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }

    int solve(int i, int sum , vector<int>&nums, int target){
        if(i >= nums.size()){
            return target == sum ? 1 : 0;
        }

        int addSum = solve(i+1, sum+nums[i], nums, target);
        int subtractSum = solve(i+1, sum-nums[i], nums, target);

        return addSum + subtractSum;
    }
};