class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int currIdx = 0;
        int intervalCount = intervals.size();

        int mergeStart = newInterval[0];
        int mergeEnd = newInterval[1];

        vector<vector<int>> ans;
        while(currIdx < intervalCount){
            int intervalEnd = intervals[currIdx][1];
            int intervalStart = intervals[currIdx][0];
            if(intervalEnd >= mergeStart) break;

            ans.push_back({intervalStart, intervalEnd});
            currIdx++;
        }

        while(currIdx < intervalCount){
            int intervalStart = intervals[currIdx][0];
            int intervalEnd = intervals[currIdx][1];

            if (intervalStart > mergeEnd) break;

            mergeStart = min(intervalStart, mergeStart);
            mergeEnd = max(intervalEnd, mergeEnd);

            currIdx++;
        }

        ans.push_back({mergeStart, mergeEnd});

        while(currIdx < intervalCount){
            ans.push_back(intervals[currIdx]);
            currIdx++;
        }

        return ans;
    }
};