class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto it : words){
            int s = 0;
            for(auto c : it){
                s += weights[c - 'a'];
            }
            ans.push_back('z' - (s%26));
        }
        return ans;
    }
};