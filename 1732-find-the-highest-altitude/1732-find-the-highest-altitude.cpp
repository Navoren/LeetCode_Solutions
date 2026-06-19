class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int alti = 0;
        int ans = 0;
        for(auto it : gain){
            alti += it;
            ans = max(ans, alti);
        }
        return ans;
    }
};