class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        fun(0, s, res, path);
        return res;
    }
    void fun(int ind, string s, vector<vector<string>> &res, vector<string> &path){
        if(ind == s.size()){
            res.push_back(path);
            return;
        }
        for(int i = ind; i<s.size(); i++){
            if(isPali(s, ind, i)){
                path.push_back(s.substr(ind, i - ind + 1));
                fun(i+1,s, res, path);
                path.pop_back();
            }
        }
    }
    bool isPali(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};