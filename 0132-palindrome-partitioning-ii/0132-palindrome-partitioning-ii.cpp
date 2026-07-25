class Solution {
public:
    bool isPalindrome(int l, int r, string&s){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int solve(int i, string&s, vector<int> &dp){
        if( i == s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int part=i; part < s.size(); part++){
            if(isPalindrome(i, part, s)){
                ans = min(ans, 1 + solve(part+1, s, dp));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, dp) - 1;
    }
};