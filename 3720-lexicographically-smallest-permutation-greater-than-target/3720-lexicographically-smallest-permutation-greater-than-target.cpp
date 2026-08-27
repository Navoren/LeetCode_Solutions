class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> left(26, 0);

        // left = characters in s - characters needed by target prefix
        for (int i = 0; i < n; i++) {
            left[s[i] - 'a']++;
            left[target[i] - 'a']--;
        }

        for (int i = n - 1; i >= 0; i--) {

            // Undo target[i]
            int cur = target[i] - 'a';
            left[cur]++;

            // Check whether target[0...i-1] can be formed.
            bool possible = true;

            for (int c = 0; c < 26; c++) {
                if (left[c] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // Find smallest character > target[i]
            for (int c = cur + 1; c < 26; c++) {
                if (left[c] > 0) {

                    string ans = target.substr(0, i);

                    // Make the first differing character larger
                    ans += char('a' + c);
                    left[c]--;

                    // Put remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        while (left[x] > 0) {
                            ans += char('a' + x);
                            left[x]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};