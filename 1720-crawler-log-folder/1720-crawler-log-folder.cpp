class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto i:logs){
            if(i == "../" && ans) ans--;
            else if(i!= "./" && i!= "../") ans++;
        }
        return ans;
    }
};