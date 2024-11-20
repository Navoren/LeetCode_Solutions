class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> count(3,0);
        for(char c : s) count[c-'a']++;
        if(count[0] < k || count[1] < k || count[2] < k) return -1;
        int l = 0, r = 0, maxWindow = 0;
        vector<int> window(3,0);

        while(r<n){
            window[s[r]-'a']++;
            while(window[0] > count[0] - k || window[1] > count[1] - k || window[2] > count[2] - k){
                window[s[l]-'a']--;
                l++;
            }
            maxWindow = max(maxWindow, r-l+1);
            r++;
        }
        return n - maxWindow;
    }
};