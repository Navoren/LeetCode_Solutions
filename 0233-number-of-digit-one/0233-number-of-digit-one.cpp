class Solution {
public:
    string s;
    int dp[11][2][2][11]; //pos, tight, started, count1
    int countDigitOne(int n) {
        s = to_string(n);
        memset(dp , -1, sizeof(dp));
        return solve(0,1,0,0);
    }

    int solve(int pos, int tight, int started, int count1){
        if(pos == s.size()){
            if(started) return count1;
            return 0;
        }

        int &res = dp[pos][tight][started][count1];
        if(res != -1) return res;

        res = 0;
        int limit = tight ? s[pos] - '0' : 9;
        for(int d = 0; d<= limit; d++){
            int newTight = tight && (d == s[pos] - '0');
            int newCount = count1 + (d == 1 ? 1 : 0);
            if(!started && d == 0){
                res += solve(pos+1, newTight, 0, newCount);
            }else{
                res += solve(pos+1, newTight, 1, newCount);
            }
        }

        return res;
    }
};