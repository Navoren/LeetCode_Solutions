class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int cnt = 1;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEnd) {
                cnt++;
                lastEnd = intervals[i][1];
            }
        }

        return n - cnt;
    }
};