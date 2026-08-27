class Solution {
public:
    string s;
    int dp[11][2][2][10];
    int countOdds(int low, int high) {
        return countOdd(high) - countOdd(low - 1);
    }

    int countOdd(int n){
        if(n<=0) return 0;
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0,1,0,0);
    }

    int solve(int pos, int tight, int started, int lastDigit){
        if(pos == s.size()){
            if(started && lastDigit%2 == 1) return 1;
            return 0;
        }

        int &res = dp[pos][tight][started][lastDigit];
        if(res != -1) return res;

        res =0;

        int limit = tight ? s[pos] - '0' : 9;
        for(int d = 0; d<=limit; d++){
            int newTight = tight && (d == s[pos] - '0');

            if(!started && d == 0){
                res += solve(pos + 1, newTight, 0, 0);
            }else{
                res += solve(pos + 1, newTight, 1, d);
            }
        } 

        return res;
    }
};