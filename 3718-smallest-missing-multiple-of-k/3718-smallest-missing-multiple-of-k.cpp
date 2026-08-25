class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto it : nums){
            st.insert(it);
        }

        int i=k;
        while(true){
            if(!st.count(i)) return i;
            i = i+k;
        }
    }
};