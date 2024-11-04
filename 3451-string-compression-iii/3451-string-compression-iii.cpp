class Solution {
public:
    string compressedString(string word) {
        stack<char> st;
        string ans;
        
        for (int i = 0; i < word.size(); i++) {
            if (st.empty() || (word[i] == st.top() && st.size() < 9)) {
                st.push(word[i]);
            } else {
                ans += to_string(st.size());
                ans += st.top();
                while (!st.empty()) st.pop();
                st.push(word[i]);
            }
        }
        if (!st.empty()) {
            ans += to_string(st.size());
            ans += st.top();
        }
        
        return ans;
    }
};
