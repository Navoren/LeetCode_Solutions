class Solution {
public:
vector<int> findNGE(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> nge(n);
    for(int i = n-1; i>=0; i--){
        while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;
}
vector<int> findPGE(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> pge(n);
    for(int i = 0; i<n; i++){
        while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pge;
}
vector<int> findNSE(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> nse(n);
    for(int i = n-1; i>=0; i--){
        while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    vector<int> pse(n);
    for(int i = 0; i<n; i++){
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge = findNGE(nums);
        vector<int> pge = findPGE(nums);
        vector<int> nse = findNSE(nums);
        vector<int> pse = findPSE(nums);

        long long largest = 0, smallest = 0;

        for (int i = 0; i < n; i++) {
            int left = i - pge[i], right = nge[i] - i;
            largest += left * 1LL * right * nums[i];
        }

        for (int i = 0; i < n; i++) {
            int left = i - pse[i], right = nse[i] - i;
            smallest += left * 1LL * right * nums[i];
        }

        long long ans = largest - smallest;
        return ans;
        
    }
};