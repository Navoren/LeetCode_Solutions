class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0;
        long long sum = 0, ans = 0;
        unordered_map<int,int> mpp;
        while(r < nums.size()){
            sum += nums[r];
            mpp[nums[r]]++;

            if(r-l+1 > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                sum -= nums[l];
                l++;
            }
            if(mpp.size() == k && (r-l+1) == k) ans = max(ans, sum);
            r++;
        }
        return ans;

    }
};