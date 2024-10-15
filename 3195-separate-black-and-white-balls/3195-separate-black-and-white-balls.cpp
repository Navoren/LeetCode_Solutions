class Solution {
public:
    long long minimumSteps(string s) {
        long white = 0;
        long ans = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='0') ans +=white;
            else if(s[i] == '1') white++;
        }
        return ans;
    }
};