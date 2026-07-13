class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1; i<=9; i++){
            dfs(i, ans, low, high);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

    void dfs(long long num , vector<int>& ans, int &low, int &high){
        if(num > high) return;
        if(num >= low) ans.push_back(num);

        int last = num%10;
        if(last == 9) return;

        dfs((num*10 + (last+1)), ans, low, high);
    }
};