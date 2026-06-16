class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        int n = intervals.size();
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];
        for(int i=1; i<n; i++){
            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1];

            if(nextStart <= currEnd){
                currEnd = max(nextEnd, currEnd);
            }else{
                merged.push_back({currStart, currEnd});
                currStart = nextStart;
                currEnd = nextEnd;
            }
        }
        merged.push_back({currStart, currEnd});
        return merged;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged = merge(intervals);
        merged.push_back(newInterval);
        sort(merged.begin(), merged.end());
        vector<vector<int>> ans = merge(merged);
        return ans;
    }
};