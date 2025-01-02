class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> ans;
        vector<int> psum(n+1, 0);
        unordered_set<int> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i=0; i<n; i++){
            psum[i+1] = psum[i];
            if(vowels.count(words[i].front()) && vowels.count(words[i].back())) psum[i+1]++;
        }
        for(auto &query : queries){
            int l = query[0];
            int r = query[1];
            ans.push_back(psum[r+1] - psum[l]);
        }
        return ans;

    }
};