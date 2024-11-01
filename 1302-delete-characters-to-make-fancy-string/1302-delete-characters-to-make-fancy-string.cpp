class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        stack<pair<char,int>> st;
        for(int i = 0; i<n; i++){
            if(st.empty()){ 
                st.push({s[i],1});
                continue;
            }
            if(s[i] == st.top().first && st.top().second == 2) continue;
            if(s[i] == st.top().first && st.top().second == 1) st.push({s[i], 2});
            if(s[i] != st.top().first) st.push({s[i], 1});
        }
        string ans;
        while(!st.empty()){
            ans  += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};