class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;
        int pivot = nums[0];
        for(int i =1 ; i<n; i++){
            if(nums[i] > pivot){
                maxDiff = max(maxDiff, nums[i] - pivot);
            }else{
                pivot = nums[i];
            }
        }
        return maxDiff;
    }
};