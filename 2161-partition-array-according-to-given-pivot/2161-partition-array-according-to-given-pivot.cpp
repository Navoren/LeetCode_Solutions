class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> larger;
        vector<int> equals;
        vector<int> ans;
        for (int num : nums) {
            if (num < pivot)
                smaller.push_back(num);
            else if (num == pivot)
                equals.push_back(num);
            else
                larger.push_back(num);
        }
        for(auto &it : smaller) ans.push_back(it);
        for(auto &it : equals) ans.push_back(it);
        for(auto &it : larger) ans.push_back(it);
        return ans;
    }
};