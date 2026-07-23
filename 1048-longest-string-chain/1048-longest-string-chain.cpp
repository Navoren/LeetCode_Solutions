class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string &a, string &b) {
                 return a.size() < b.size();
            });
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(check(words[i], words[j])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }

    bool check(string s1, string s2){
        if(s1.size() != s2.size()+1) return false;

        int i=0, j=0;
        while(i < s1.size()){
            if(j < s2.size() && s1[i] == s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }

        return j == s2.size();
    }
};