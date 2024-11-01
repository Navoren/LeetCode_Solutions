class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.size();
        int cnt = 1;
        ans.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(s[i] == ans.back()){
                cnt++;
                if(cnt < 3)ans.push_back(s[i]);
            }
            else{
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};