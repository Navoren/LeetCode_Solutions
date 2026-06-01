class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int ans = 0;
        int buy = cost.size()-1;
        while(buy>=0){
            if(buy<1){
                ans += cost[0];
                break;
            }
            ans += cost[buy] + cost[buy-1];
            buy = buy-3;
        } 
        return ans;     
    }
};