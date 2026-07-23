class Solution {
public:
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
    int lcs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1,m-1, text1, text2, dp);
    }

    int helper(int i, int j, string& s1, string& s2, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + helper(i-1, j-1, s1, s2, dp);
        }

        return dp[i][j] = max(
            helper(i-1, j, s1, s2,dp),
            helper(i, j-1, s1, s2,dp)
        );
    }
};