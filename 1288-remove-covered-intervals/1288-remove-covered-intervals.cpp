class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int maxEnd = INT_MIN;
        int ans =0;
        for(int i=0; i<n; i++){
            auto frame = intervals[i];
            if(frame[1] > maxEnd){
                ans++;
                maxEnd = frame[1];
            }
        }

        return ans;
    }
};