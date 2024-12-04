class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int srcIdx = 0, tgtIdx = 0;
        while(srcIdx < str1.size() && tgtIdx < str2.size()){
            if((str1[srcIdx] == str2[tgtIdx]) || (str1[srcIdx] == 'z' && str2[tgtIdx] == 'a') || (str1[srcIdx] + 1 == str2[tgtIdx])){
                srcIdx++;
                tgtIdx++;
            }
            else srcIdx++;
        }
        return tgtIdx == str2.size();
    }
};