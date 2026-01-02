class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> mpp;
        for(int i : nums){
            mpp[i]++;
        }
        for(auto &ele : mpp){
            if(ele.second == size/2){
               return ele.first;
            }
        }
        return -1;
    }
};