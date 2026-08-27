class Solution {
public:
    string s;
    int dp[11][2][2][2];
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int x : nums){
            int a = countEvenDigits(x);
            int b = countEvenDigits(x-1);

            if(a - b == 1) ans++;
        }

        return ans;
    }

    int countEvenDigits(int n){
        s = to_string(n);
        memset(dp, -1, sizeof(dp));

        return solve(0,1,0,0);
    }

    int solve(int pos, int tight, int started, int parity){
        if(pos == s.size()){
            if(started && parity == 0) return 1;
            return 0;
        }

        int &res = dp[pos][tight][started][parity];

        if(res != -1) return res;

        res = 0;

        int limit = tight ? s[pos] - '0' : 9;

        for(int d =0; d<= limit; d++){
            int newTight = tight && ( d == s[pos] - '0');

            if(!started && d == 0){
                res += solve(pos+1, newTight, 0, 0);
            }else{
                res += solve(pos+1, newTight, 1, parity^1);
            }
        }

        return res;
    }
};