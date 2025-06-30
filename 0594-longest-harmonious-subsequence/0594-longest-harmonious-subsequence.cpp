class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int right = 0, maxLen = 0;
        for(int left = 0; left < nums.size(); left++){
            while(nums[left] - nums[right] > 1){
                right++;
            }
            if(nums[left] - nums[right] == 1){
                maxLen = max(maxLen, left-right+1);
            }
        }
        return maxLen;
        
    }
};