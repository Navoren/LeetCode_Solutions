class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0, rSum = 0, maxSum = 0;
        for(int i=0; i<k; i++) lSum = lSum + cardPoints[i];
        maxSum = lSum;
        int rIndex = cardPoints.size() - 1;
        int sum = lSum;
        for(int i = k-1; i>=0; i--){
            lSum = lSum - cardPoints[i];
            rSum = rSum + cardPoints[rIndex];
            sum = lSum + rSum;
            maxSum = max(maxSum, sum);
            rIndex--;
        }
        return maxSum;
    }
};