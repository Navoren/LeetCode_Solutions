class Solution {
private:
void subsem2(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
    if(ind >= nums.size()){
    ans.push_back(ds);
    return;
    }
    ds.push_back(nums[ind]);
    subsem2(ind+1, nums, ans, ds);
    ds.pop_back();
    while(ind+1 < nums.size() && nums[ind+1] == nums[ind]) ind++;
    subsem2(ind+1, nums, ans, ds);
}    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        subsem2(0, nums, ans, ds);
        return ans;
    }
};