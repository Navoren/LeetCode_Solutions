class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        int hash[256] = {0};
        for (char c : t) {
            hash[c]++;
        }

        int l = 0, r = 0;
        int min_len = INT_MAX;
        int start = 0;
        int count = t.size(); 

        while (r < s.size()) {
      
            if (hash[s[r]] > 0) {
                count--;
            }
            hash[s[r]]--;
            r++;

       
            while (count == 0) {
          
                if (r - l < min_len) {
                    min_len = r - l;
                    start = l;
                }

             
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count++;
                }
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};