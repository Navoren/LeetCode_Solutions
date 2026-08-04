class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> ans;
        int maxEle = *max_element(nums.begin(), nums.end());
        int minEle = *min_element(nums.begin(), nums.end());

        for(int i = minEle; i<= maxEle; i++){
            if(!st.count(i)) ans.push_back(i);
        }

        return ans;
    }
};