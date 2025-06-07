class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> pq;
        unordered_map<int, bool> mpp;
        for(int i = 0; i<n; i++){
            if(s[i] == '*'){
                mpp[-pq.top().second] = true;
                pq.pop();
            }else{
                pq.push({s[i], -i});
            }
        }
        string res;
        for(int i=0; i< s.size(); i++){
            if(mpp.count(i) || s[i] == '*') continue;
            res += s[i];
        }
        return res;
        
    }
};