class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        if (result.empty()) {
            return "0";
        }
        return result;
    }
};