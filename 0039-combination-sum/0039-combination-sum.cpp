class Solution {
public: 
vector<vector<int>> ans;

void seq(vector<int>& candidates, int target, int i, int currSum, vector<int> temp){

    if(currSum > target){
        return;
    }

    if(i == candidates.size()){
        if(currSum == target){
            ans.push_back(temp);
        }
        return;
    }

    currSum+= candidates[i];
    temp.push_back(candidates[i]);
    seq(candidates, target, i, currSum, temp);
    currSum-=candidates[i];
    temp.pop_back();

    seq(candidates, target, i+1, currSum, temp);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        seq(candidates, target, 0, 0, temp);
        return ans;
        
    }
};