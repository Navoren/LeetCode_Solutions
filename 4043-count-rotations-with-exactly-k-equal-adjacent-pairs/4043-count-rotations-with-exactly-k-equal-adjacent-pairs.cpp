class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();

        int equalCycle = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == s[(i + 1) % n]) {
                ++equalCycle;
            }
        }

        int ans = 0;
        for (int start = 0; start < n; ++start) {
            int previous = (start - 1 + n) % n;
            int score = equalCycle - (s[previous] == s[start] ? 1 : 0);
            if (score == k) {
                ++ans;
            }
        }

        return ans;
    }
};