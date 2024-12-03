class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string new_s; 
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (j < spaces.size() && i == spaces[j]) {
                new_s += ' ';
                j++;
            }
            new_s += s[i]; 
        }

        return new_s;
    }
};
