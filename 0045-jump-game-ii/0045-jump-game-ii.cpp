class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int near = 0, far = 0;
        int ans = 0;
        while(far < n-1){
            int longestJump = 0;
            for(int i = near; i<= far; i++){
                longestJump = max(longestJump, i + nums[i]);
            }

            near = far + 1;
            far = longestJump;
            ans++;
        }

        return ans;
    }
};