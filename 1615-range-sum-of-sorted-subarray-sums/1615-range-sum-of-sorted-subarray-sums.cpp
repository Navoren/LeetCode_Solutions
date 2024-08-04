class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> newArr;
        for(int i = 1; i<=n; i++){
            int wind_size = i;
            int start = 0;
            int end = 0;
            int sum = 0;

            while(start <= end && end < n){
                sum += nums[end];
                if(end - start + 1 == wind_size){
                    newArr.push_back(sum);
                    sum -= nums[start];
                    start++;
                }
                end++;
            }
        }

        sort(newArr.begin(), newArr.end());

        left--;
        right--;

        int result = 0;
        int mod = 1e9 + 7;

        for(int i = left; i<= right; i++){
            result += newArr[i];
            result = result % mod;
        }

        return result % mod;
    }
};