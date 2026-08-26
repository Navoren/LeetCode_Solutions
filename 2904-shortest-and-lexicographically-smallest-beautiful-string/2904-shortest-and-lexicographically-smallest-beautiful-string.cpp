class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int ones = 0;
        int l = 0;
        for(int r=0; r<n; r++){
            if(s[r] == '1') ones++;

            while(ones > k){
                ones -= s[l] - '0';
                l++;
            }

            if(ones == k){
                while(s[l] == '0') l++;

                string curr = s.substr(l, r-l+1);
                if(ans == "" || curr.length() < ans.length() || (curr.length() == ans.length() && curr < ans)){
                    ans = curr;
                }
            }
        }

        return ans;
    }
};