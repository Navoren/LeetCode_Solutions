class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int left = 0;
        int right = n - 1;
        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                ans[left++] = nums[i];
            }
        }

        for(int i = n-1; i>=0; i--){
            if(nums[i] > pivot){
                ans[right--] = nums[i];
            }
        }

        while(left <= right){
            ans[left++] = pivot;
        }

        return ans;
    }
};