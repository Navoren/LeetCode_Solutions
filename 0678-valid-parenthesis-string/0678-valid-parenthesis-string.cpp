class Solution {
public:
    bool checkValidString(string s) {
        vector<int> bracs;
        vector<int> stars;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '(') bracs.push_back(i);
            else if(s[i] == '*') stars.push_back(i);
            else if(s[i] == ')'){
                if(stars.empty() && bracs.empty()) return false;
                if(!bracs.empty()) bracs.pop_back();
                else stars.pop_back();
            }
        }
        while(!bracs.empty()){
            if(stars.empty()) return false;
            if(stars.back() < bracs.back()) return false;
            stars.pop_back();
            bracs.pop_back();
        }

        return true;
    }
};