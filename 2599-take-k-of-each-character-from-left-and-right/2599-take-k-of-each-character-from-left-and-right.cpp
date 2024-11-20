class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> count(3, 0);

        for (char c : s) count[c - 'a']++;
        if (count[0] < k || count[1] < k || count[2] < k) return -1;

        int maxWindow = 0, left = 0;
        vector<int> window(3, 0);

        for (int right = 0; right < n; ++right) {
            window[s[right] - 'a']++;

            while (window[0] > count[0] - k || window[1] > count[1] - k || window[2] > count[2] - k) {
                window[s[left] - 'a']--;
                left++;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return n - maxWindow;
    }
};
