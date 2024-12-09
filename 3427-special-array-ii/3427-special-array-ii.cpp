class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<bool> ans;

        //Count for teams in prefix array
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1];
            if ((nums[i - 1] % 2 == nums[i] % 2 )) prefix[i]++;
        }
        
        //Processing Queries
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
            ans.push_back(specialCount == 0);
        }

        return ans;
    }
};