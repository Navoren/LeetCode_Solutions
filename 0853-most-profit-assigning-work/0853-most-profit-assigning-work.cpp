class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n =difficulty.size();
        int m = worker.size();

        vector<pair<int,int>> maxPair;
        for(int i = 0; i< n; i++){
            maxPair.push_back({difficulty[i], profit[i]});
        }

        sort(maxPair.begin(), maxPair.end());
        sort(worker.begin(), worker.end());

        int totalProfit = 0;
        int j = 0;
        int maxProfit = 0;

        for(int i = 0; i< m; i++){
            while( j < n && worker[i] >= maxPair[j].first){
                maxProfit = max(maxProfit, maxPair[j].second);
                j++;
            }
            totalProfit += maxProfit;
        }

        return totalProfit;


    }
};