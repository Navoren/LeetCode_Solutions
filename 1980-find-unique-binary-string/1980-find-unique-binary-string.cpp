class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i=0; i<nums.size(); i++){
            char ch = nums[i][i];
            ans += ch == '1' ? '0' : '1';
        }
        return ans;
    }
};