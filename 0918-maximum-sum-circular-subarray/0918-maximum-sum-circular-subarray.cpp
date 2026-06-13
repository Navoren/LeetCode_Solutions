class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int minSum = nums[0];
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
            if(i>0){
                int v1 = maxEnding + nums[i];
                int v2 = nums[i];
                int v3 = minEnding + nums[i];
                maxEnding = max(v1, v2);
                minEnding = min(v2, v3);
                maxSum = max(maxSum, maxEnding);
                minSum = min(minSum, minEnding);
            }
        }

        if(maxSum < 0){
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};