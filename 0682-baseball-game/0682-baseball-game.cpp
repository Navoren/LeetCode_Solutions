class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "+") {
                int n1 = st.top(); st.pop();
                int n2 = st.top();
                st.push(n1);
                st.push(n1 + n2);
            }
            else if (ops[i] == "C") {
                st.pop();
            }
            else if (ops[i] == "D") {
                st.push(2 * st.top());
            }
            else {
                st.push(stoi(ops[i]));
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
