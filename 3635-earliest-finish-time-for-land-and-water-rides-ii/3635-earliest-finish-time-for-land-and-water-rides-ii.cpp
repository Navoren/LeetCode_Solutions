class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int landFinish = INT_MAX;
        int waterFinish = INT_MAX;
        int landThenWater = INT_MAX;
        int waterThenLand = INT_MAX;
        for(int i=0; i<n; i++){
            landFinish = min(landFinish, landStartTime[i] + landDuration[i]);
        }

        for(int j=0; j<m; j++){
            landThenWater = min(landThenWater, max(landFinish, waterStartTime[j]) + waterDuration[j]);
        }

        for(int j=0; j<m; j++){
            waterFinish = min(waterFinish, waterStartTime[j] + waterDuration[j]);
        }

        for(int i=0; i<n; i++){
            waterThenLand = min(waterThenLand, max(waterFinish, landStartTime[i]) + landDuration[i]);
        }

        return min(waterThenLand, landThenWater);
    }
};