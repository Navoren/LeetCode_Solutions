class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, maxLen = 0;

        int hash[256];
        fill(hash, hash+256, -1);

        while(r<n){
            if(hash[s[r]] != -1 && hash[s[r]] >= l){
                l = hash[s[r]] + 1;
        }
        maxLen = max(maxLen, r-l+1);
        hash[s[r]] = r;
        r++;
    }
    return maxLen;
    }
};