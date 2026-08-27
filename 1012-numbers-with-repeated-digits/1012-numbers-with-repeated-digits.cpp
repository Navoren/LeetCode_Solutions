class Solution {
public:
    string s;
    int dp[11][1 << 10][2][2];
    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));

        int unique = solve(0,0,1,0);

        return n - unique;
    }

    int solve(int pos, int mask, int tight, int started){
        if(pos == s.size()){
            return started ? 1 : 0;
        }

        int &res = dp[pos][mask][tight][started];

        if(res != -1 ) return res;

        res = 0;

        int limit = tight ? s[pos] - '0' : 9;

        for(int d = 0; d<=limit; d++){
            int newTight = tight && (d == s[pos] - '0');

            if(!started && d == 0){
                res += solve(pos+1, mask, newTight, 0);
            }else{
                if(mask & (1 << d)) continue;
                int newMask = mask | (1 << d);
                res += solve(pos+1, newMask, newTight, 1);
            }
        }

        return res;
    }
};