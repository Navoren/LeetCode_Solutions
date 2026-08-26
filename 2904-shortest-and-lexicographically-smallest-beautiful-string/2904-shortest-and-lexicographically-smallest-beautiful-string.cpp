class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";

        for (int l = 0; l < n; l++) {
            int sum = 0;

            for (int r = l; r < n; r++) {
                sum += s[r] - '0';

                if (sum == k) {
                    string curr = s.substr(l, r - l + 1);

                    if (ans == "" || curr.length() < ans.length() || (curr.length() == ans.length() && curr < ans)) {
                        ans = curr;
                    }
                    break;
                }

                if (sum > k) break;
            }
        }

        return ans;
    }
};