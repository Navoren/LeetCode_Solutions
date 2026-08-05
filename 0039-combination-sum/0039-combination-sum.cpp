class Solution {
public:
int n;
vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> temp;
        backtrack(0, target, candidates, temp);
        return ans;
    }

    void backtrack(int i, int target, vector<int>&candidates, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(i == n || target < 0){
            return;
        }

        temp.push_back(candidates[i]);
        backtrack(i, target - candidates[i], candidates, temp);
        temp.pop_back();

        backtrack(i+1, target, candidates, temp);
    }
};