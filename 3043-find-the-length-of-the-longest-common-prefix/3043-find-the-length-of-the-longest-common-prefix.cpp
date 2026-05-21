class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {       
        unordered_set<string> st;
        
        for (int num : arr1) {
            string s = to_string(num);
            string prefix = "";

            for (char c : s) {
                prefix += c;
                st.insert(prefix);
            }
        }

        int ans = 0;
        for (int num : arr2) {
            string s = to_string(num);
            string prefix = "";

            for (int i = 0; i < s.length(); i++) {
                prefix += s[i];

                if (st.find(prefix) != st.end()) {
                    ans = max(ans, i + 1);
                }
            }
        }

        return ans;
    }
};