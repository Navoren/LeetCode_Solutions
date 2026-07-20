class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        int excludeLast = solve(nums, 0, n - 2);
        int excludeFirst = solve(nums, 1, n - 1);

        return max(excludeLast, excludeFirst);
    }

    int solve(vector<int>& nums, int start, int end){
        int prev2 = 0;
        int prev1 = 0;

        for(int i= start; i <=end; i++){
            int pick = nums[i] + prev2;
            int notPick = prev1;

            int curr = max(pick, notPick);

            prev2 = prev1;
            prev1 = curr; 
        }
        return prev1;
    }
};