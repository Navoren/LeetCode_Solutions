class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char, pair<int, int>> mpp;

        for(int i = 0; i<n; i++){
            if(mpp.find(s[i]) == mpp.end()){
                mpp[s[i]].first = i;
            }
            mpp[s[i]].second = i;
        }

        for(auto& [ch, positions] : mpp){
            int left = positions.first;
            int right = positions.second;

            if(right - left <= 1) continue;

            unordered_set<char> uniqChars;
            for(int i = left+1; i<right; i++){
                uniqChars.insert(s[i]);
            }

            ans+= uniqChars.size();
        }
        return ans;
    }
};