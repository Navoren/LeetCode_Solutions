class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mpp;
        for(auto it : magazine){
            mpp[it]++;
        }
        for(int i=0; i<ransomNote.size(); i++){
            if(mpp[ransomNote[i]] <= 0){
                return false;
            }
            mpp[ransomNote[i]]--;
        }
        return true;
    }
};