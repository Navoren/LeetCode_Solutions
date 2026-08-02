class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n);

        suffix[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, 1, suffix, piles, dp);
    }

    int solve(int i, int M, vector<int>&suffix, vector<int>&piles, vector<vector<int>> &dp){
        int n = piles.size();

        if(i >= n) return 0;
        if( i + 2*M >= n) return suffix[i];
        if(dp[i][M] != -1) return dp[i][M];

        int ans = 0;
        for(int x=1; x<=2*M; x++){
            ans = max(ans, suffix[i] - solve(i+x, max(x,M), suffix, piles, dp));
        }
        
        return dp[i][M] = ans;
    }
};