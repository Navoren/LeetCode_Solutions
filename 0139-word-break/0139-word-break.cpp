class Solution {
public:
    bool solve(int start,
               string &s,
               vector<string>& wordDict,
               vector<int>& dp) {

        if (start == s.size())
            return true;

        if (dp[start] != -1)
            return dp[start];

        for (string word : wordDict) {

            if (s.find(word, start) == start) {

                if (solve(start + word.size(), s, wordDict, dp))
                    return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> dp(s.size(), -1);

        return solve(0, s, wordDict, dp);
    }
};