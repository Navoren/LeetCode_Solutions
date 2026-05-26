class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        for(char ch = 'a'; ch<='z'; ch++){
            int lower = 0;
            int upper = 0;

            for(char c : word){
                if(c == ch){
                    lower = 1;
                }
                if(c == ch - 'a' + 'A'){
                    upper = 1;
                }
            }
            if(lower && upper) count++;
        }
        return count;
    }
};