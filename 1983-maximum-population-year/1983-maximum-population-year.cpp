class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++){
            for(int j=logs[i][0]; j< logs[i][1]; j++){
                mpp[j]++;
            }
        }
        int maxi = INT_MIN;
        int maxYear = 0;
        for(auto x: mpp){
            if(x.second > maxi){
                maxi = x.second;
                maxYear = x.first;
            }
            else if(x.second == maxi && x.first < maxYear){
                maxYear = x.first;
            }
        }
        return maxYear;
    }
};