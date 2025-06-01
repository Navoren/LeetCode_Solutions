class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        int curr_sum = 0;
        int count = 0;

        for(int i = 0; i< nums.size(); i++){
            curr_sum += nums[i];

            if(mpp.find(curr_sum - k) != mpp.end()){
                count += mpp[curr_sum - k];
            }
            mpp[curr_sum]++;
        }
        return count;
        
    }
};