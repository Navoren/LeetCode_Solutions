class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> need, have;
        int mini = INT_MAX;

        string s = "balloon";
        for(auto it : s){
            have[it]++;
        }

        for(auto it : text){
            need[it]++;
        }

        for(auto it : have){
            int q = need[it.first] / have[it.first];
            mini = min(mini, q);
        }

        return mini;
    }
};