class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<char> st;
        int i =0;
        while(i<n){
            if(path[i] == '/'){
                i++;
                if(st.empty() || st.top() != '/') st.push('/');
            }
            else if(st.top() == '/' && path[i] == '.' && path[i+1] == '.' && (i+2 == n || path[i+2] == '/')){
                if(st.size() != 1) st.pop();
                while(st.top() != '/') st.pop();
                i += 2;
            }
            else if(st.top() == '/' && path[i] == '.' && (i+1 == n || path[i+1] == '/')){
                i++;
            }
            else{
                st.push(path[i]);
                i++;
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans.size() > 1 && ans.back() == '/') ans.pop_back();
        return ans;
        
    }
};