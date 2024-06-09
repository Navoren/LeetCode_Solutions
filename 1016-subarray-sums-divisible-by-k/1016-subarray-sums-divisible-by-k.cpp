class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp = {{0, 1}};
        int sum = 0, ans = 0;
        for(int i = 0; i<nums.size(); i++){
            sum = (sum + nums[i]) % k;
            if(sum < 0) sum += k;
            if(mpp.find(sum) != mpp.end()){
                ans += mpp[sum];
                mpp[sum]++;
            }
            else{
                mpp[sum] = 1;
            }
        }
        return ans;
    }
};