class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = 0;
        unordered_map<int,int> mpp;
        int ans = 0;
        mpp[0] = 1;
        for(auto it : nums){
            totalSum += it;

            if(mpp.find(totalSum - k) != mpp.end()){
                ans += mpp[totalSum - k];
            }
            mpp[totalSum]++;
        }

        return ans;
    }
};