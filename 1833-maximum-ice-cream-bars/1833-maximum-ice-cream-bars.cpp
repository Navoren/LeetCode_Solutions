class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int MAX_INT = 100001;
        vector<int> freq(MAX_INT, 0);

        for(auto &it : costs){
            freq[it]++;
        }

        int ans = 0;

        for(int i=1; i<MAX_INT; i++){
            if(freq[i] == 0) continue;

            int buy = min(freq[i], coins/i);

            ans += buy;
            coins -= buy*i;

            if(coins < i) break;
        }

        return ans;
    }
};