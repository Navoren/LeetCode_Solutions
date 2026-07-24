class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 1;
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mpp;
        for(auto it : nums){
            mpp[it] = 1;
        }

        int t;
        for(int i = 1; i < n; i++){
            t = k;
            int j = i - 1;
            if(nums[i] == nums[j]){
                mpp[nums[i]]++;
                maxi = max(maxi,mpp[nums[i]]);
            }

            else{
                while(t>0 && j>=0){
                    t = t - (nums[i] - nums[j]);
                    if(t >= 0) mpp[nums[i]]++;
                    j--;
                    maxi = max(maxi,mpp[nums[i]]);
                }
            }
        }

        return maxi;

    }
};