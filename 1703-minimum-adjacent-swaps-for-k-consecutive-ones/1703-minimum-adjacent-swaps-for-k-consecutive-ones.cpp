class Solution {
public:
    int minMoves(vector<int>& nums, int k) {

        vector<int> pos;

        // Store positions of 1s
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1)
                pos.push_back(i);
        }

        int n = pos.size();

        // Prefix sum of positions
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + pos[i];
        }

        long long answer = LLONG_MAX;

        for(int l = 0; l + k <= n; l++) {

            int r = l + k - 1;

            // Median index
            int m = l + k / 2;

            long long median = pos[m];

            // Number of elements on the left
            long long leftCount = m - l;

            // Sum of positions on the left
            long long leftSum =
                prefix[m] - prefix[l];

            /*
                Desired positions for the left side are:

                median - 1
                median - 2
                ...
                median - leftCount

                Their sum is:
                
                leftCount * median
                - (1 + 2 + ... + leftCount)
            */

            long long leftTargetSum =
                leftCount * median
                - leftCount * (leftCount + 1) / 2;

            long long leftCost =
                leftTargetSum - leftSum;


            // Number of elements on the right
            long long rightCount =
                r - m;

            // Sum of positions on the right
            long long rightSum =
                prefix[r + 1] - prefix[m + 1];

            /*
                Desired positions:

                median + 1
                median + 2
                ...
            */

            long long rightTargetSum =
                rightCount * median
                + rightCount * (rightCount + 1) / 2;

            long long rightCost =
                rightSum - rightTargetSum;


            long long totalCost =
                leftCost + rightCost;

            answer = min(answer, totalCost);
        }

        return answer;
    }
};