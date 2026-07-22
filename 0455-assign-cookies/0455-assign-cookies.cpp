class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child =0;
        int idx = 0;
        while(idx < s.size() && child < g.size()){
            if(s[idx] >= g[child]) child++;
            idx++;
        }

        return child;
    }
};