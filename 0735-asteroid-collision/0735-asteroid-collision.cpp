class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        
        for (int asteroid : arr) {
            bool destroyed = false;
            
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (st.top() < -asteroid) {
                    st.pop();
                    continue;
                } else if (st.top() == -asteroid) {
                    st.pop();
                }
                
                destroyed = true;
                break;
            }
            
            if (!destroyed) {
                st.push(asteroid);
            }
        }
        
        int s = st.size();
        vector<int> result(s);
        for (int i = s - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};
