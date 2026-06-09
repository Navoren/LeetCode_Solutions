class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int gMin = nums[0]; 
        int gMax = nums[0];

        for (auto& it : nums) {
            gMin = min(gMin, it);
            gMax = max(gMax, it);
        }
        
        return (long long)(gMax - gMin) * k;
    }
};