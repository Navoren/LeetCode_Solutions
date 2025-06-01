class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int totalProfit = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            int buy = 0;
            int sell = 0;
            if(nums[i-1] < nums[i]){
                buy = nums[i-1];
                sell = nums[i];
            }
            int profit = sell - buy;
            totalProfit += profit;
            buy = 0;
            sell = 0;
        }
        return totalProfit;
    }
};