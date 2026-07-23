class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        lcs(s1, s2, dp);

        int i = n - 1;
        int j = m - 1;
        string ans = "";

        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                ans += s1[i];
                i--;
                j--;
            }
            else {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;

                if (up >= left) {
                    ans += s1[i];
                    i--;
                } else {
                    ans += s2[j];
                    j--;
                }
            }
        }

        while (i >= 0) {
            ans += s1[i];
            i--;
        }

        while (j >= 0) {
            ans += s2[j];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    int lcs(string text1, string text2, vector<vector<int>>& dp) {
        return helper(text1.size() - 1, text2.size() - 1, text1, text2, dp);
    }

    int helper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + helper(i - 1, j - 1, s1, s2, dp);
        }

        return dp[i][j] = max(
            helper(i - 1, j, s1, s2, dp),
            helper(i, j - 1, s1, s2, dp)
        );
    }
};