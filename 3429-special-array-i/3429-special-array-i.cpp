class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n-1){
            if(nums[i]%2 == nums[i+1]%2) return false;
            i++;
        }
        return true;
    }
};