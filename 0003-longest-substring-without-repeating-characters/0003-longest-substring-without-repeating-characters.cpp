class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxiLen = 0;
        int start = 0;
        unordered_map<char,int> freq;
        for(int i = 0; i<s.length(); i++){
            char current = s[i];

            if(freq.find(current) != freq.end() && freq[current] >= start){
                start = freq[current] + 1;
            }
            freq[current] = i;

            maxiLen = max(maxiLen, i - start + 1);
        }
        return maxiLen;
    }
};