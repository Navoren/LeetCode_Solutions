class Solution {
public:
    void generateSums(int ind, int count, int sum, vector<int>&arr, vector<vector<int>>& sums){
        if(ind == arr.size()){
            sums[count].push_back(sum);
            return;
        }

        generateSums(ind+1, count, sum , arr, sums);
        generateSums(ind+1, count+1, sum + arr[ind], arr, sums);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() /2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() +n, nums.end());

        vector<vector<int>> leftSums(n+1);
        vector<vector<int>> rightSums(n+1);

        generateSums(0,0,0,left, leftSums);
        generateSums(0,0,0,right, rightSums);

        for(int k=0; k<=n; k++){
            sort(rightSums[k].begin(), rightSums[k].end());
        }

        int total = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = INT_MAX;

        for(int leftCount = 0; leftCount < n; leftCount++){
            int rightCount = n - leftCount;

            for(int leftSum : leftSums[leftCount]){
                double target = total / 2.0 - leftSum;

                auto& candidates = rightSums[rightCount];
                auto it = lower_bound(candidates.begin(), candidates.end(), target);

                if(it != candidates.end()){
                    int chosenSum = leftSum + *it;
                    ans = min(ans, abs((int) total - 2*chosenSum));
                }

                if(it != candidates.begin()){
                    it--;
                    int chosenSum = leftSum + *it;
                    ans = min(ans, abs((int) total - 2*chosenSum));
                }
            }
        }
        return ans;
    }
};