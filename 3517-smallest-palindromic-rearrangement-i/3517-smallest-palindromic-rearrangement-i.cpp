class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for(int i=0; i<n/2; i++){
            freq[s[i] - 'a']++;
        }

        int j=0;
        for(int i=0; i<26; i++){
            while(freq[i] > 0){
                s[j] = 'a' + i;
                s[n-1-j] = 'a' + i;
                j++;
                freq[i]--;
            }
        }
        return s;
    }
};