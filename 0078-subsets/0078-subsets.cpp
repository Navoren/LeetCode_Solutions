class Solution {
public:
int n;
vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(0,temp, nums);
        return ans;
    }

    void solve(int i,vector<int>&temp, vector<int>&nums){
        if(i == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1, temp, nums);

        temp.pop_back();
        solve(i+1, temp, nums);
    }
};