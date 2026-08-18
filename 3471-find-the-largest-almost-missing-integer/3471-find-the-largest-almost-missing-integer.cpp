class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }

        if(k == n) return *max_element(nums.begin(), nums.end());
        if(k == 1){
            int ans = -1;
            for(auto it : nums){
                if(mpp[it] == 1 && it > ans){
                    ans = it;
                }
            }
            return ans;
        }

        if(nums[0] == nums[n-1]) return -1;
        if(mpp[nums[0]] == 1 && mpp[nums[n-1]] == 1) return max(nums[0], nums[n-1]);
        if(mpp[nums[0]] == 1 && mpp[nums[n-1]] > 1) return nums[0];
        if(mpp[nums[n-1]] == 1 && mpp[nums[0]] > 1) return nums[n-1];

        return -1;
    }
};