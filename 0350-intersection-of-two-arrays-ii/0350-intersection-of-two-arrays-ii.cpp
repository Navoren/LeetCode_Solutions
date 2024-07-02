class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> st1(begin(nums1),end(nums1));
        multiset<int> st2(begin(nums2),end(nums2));
        vector<int> ans;
        set_intersection(begin(st1),end(st1),begin(st2),end(st2),back_inserter(ans));
        return ans;
    }
};