class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(auto &it : nums){
            totalSum += it;
        }
        int left = 0;
        for(int i=0; i<n; i++){
            int right = totalSum - left - nums[i];
            if(left == right) return i;
            left += nums[i];
        }
        return -1;
    }
};