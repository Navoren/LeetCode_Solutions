class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxOR =0;
        for(int x : nums){
            maxOR |= x;
        }

        return dfs(0, nums, 0, maxOR);
    }

    int dfs(int ind, vector<int>&nums, int currOR, int maxOR){
        if(ind == nums.size()){
            if(currOR == maxOR) return 1;
            return 0;
        }

        if(currOR == maxOR){
            return 1 << (nums.size() - ind);
        }

        return dfs(ind+1, nums, currOR, maxOR) + dfs(ind+1, nums, currOR | nums[ind], maxOR);
    }
};