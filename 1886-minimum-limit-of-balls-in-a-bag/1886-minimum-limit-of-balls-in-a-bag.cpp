class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        //sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());;
        int ans = high;

        while(low<=high){
            int mid = (low + high)/2;
            int ops = 0;

            for(int n : nums){
                ops += (n-1)/mid;
                if(ops>maxOperations) break;
            }

            if(ops <= maxOperations){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};