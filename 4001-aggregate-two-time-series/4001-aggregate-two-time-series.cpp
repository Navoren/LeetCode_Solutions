class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n = series1.size();
        int m = series2.size();
        int i=0, j=0;
        while(i<n || j<m){
            int timestamp;
            if(i == n) timestamp = series2[j][0];
            else if(j == m) timestamp = series1[i][0];
            else timestamp = min(series1[i][0], series2[j][0]);
            int val1 = (i < n) ? series1[i][1] : 0;
            int val2 = (j < m) ? series2[j][1] : 0;

            ans.push_back({timestamp, val1 + val2});

            if (i < n && series1[i][0] == timestamp) i++;
            if (j < m && series2[j][0] == timestamp) j++;
        }
        return ans;
    }
};