class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> mergedIntervals;

        int currentIndex = 0;
        int intervalCount = intervals.size();

        int mergedStart = newInterval[0];
        int mergedEnd = newInterval[1];
        
        while (currentIndex < intervalCount) {
            int intervalEnd = intervals[currentIndex][1];

            if (intervalEnd >= mergedStart) {
                break;
            }

            mergedIntervals.push_back(intervals[currentIndex]);
            currentIndex++;
        }

        while (currentIndex < intervalCount) {
            int intervalStart = intervals[currentIndex][0];
            int intervalEnd = intervals[currentIndex][1];

            if (intervalStart > mergedEnd) {
                break;
            }

            mergedStart = min(mergedStart, intervalStart);
            mergedEnd = max(mergedEnd, intervalEnd);

            currentIndex++;
        }

        mergedIntervals.push_back({mergedStart, mergedEnd});

        while (currentIndex < intervalCount) {
            mergedIntervals.push_back(intervals[currentIndex]);
            currentIndex++;
        }

        return mergedIntervals;
    }
};