class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }

        for(int i=0; i<n; i++){
            if(mpp[nums[i]] == 1) return nums[i];
        }

        return -1;
    }
};