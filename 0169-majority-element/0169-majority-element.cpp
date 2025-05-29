class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++;
        }
        n = n/2;
        for(auto m : mpp){
            if(m.second > n) return m.first;
        }
        return 0;
    }
};