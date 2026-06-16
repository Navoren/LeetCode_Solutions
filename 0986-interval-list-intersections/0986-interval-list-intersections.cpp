class Solution {
public:
    vector<vector<int>> intervalIntersection(
        vector<vector<int>>& firstList,
        vector<vector<int>>& secondList) {

        vector<vector<int>> intersections;

        int n = firstList.size();
        int m = secondList.size();

        int i = 0;
        int j = 0;

        while (i < n && j < m) {

            int firstStart = firstList[i][0];
            int firstEnd   = firstList[i][1];

            int secondStart = secondList[j][0];
            int secondEnd   = secondList[j][1];

            int overlapStart = max(firstStart, secondStart);
            int overlapEnd   = min(firstEnd, secondEnd);

            if (overlapStart <= overlapEnd) {
                intersections.push_back({overlapStart, overlapEnd});
            }

            if (firstEnd < secondEnd) {
                i++;
            } else {
                j++;
            }
        }

        return intersections;
    }
};