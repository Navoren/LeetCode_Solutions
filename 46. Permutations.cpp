class Solution {
private:
void permuteuntil(vector<int> &nums, int i, int &numssize, vector<vector<int>> &ans){
    if(i == numssize){
        ans.push_back(nums);
    }

    for(int j = i; j<numssize; j++){
        swap(nums[i], nums[j]);
        permuteuntil(nums, i+1, numssize, ans);
        swap(nums[i], nums[j]);
    }

}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int numssize = nums.size();
        permuteuntil(nums, 0, numssize, ans);
        return ans;

    }
};
