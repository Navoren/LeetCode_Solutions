class Solution {
public:
    int setBits(int num) {
        int count = 0;
        for (int i = 31; i >= 0; --i) {
            if ((num >> i) & 1) {
                count++;
            }
        }
        return count;
    }

    bool check(const vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    bool canSortArray(vector<int>& nums) {
        vector<int> count(nums.size());
        for (int j = 0; j < nums.size(); j++) {
            count[j] = setBits(nums[j]);
        }

        int n = nums.size();
        int k = 0;
        while (k < n) {
            for (int i = 1; i < n; i++) {
                if (count[i] == count[i - 1] && nums[i] < nums[i - 1]) {
                    swap(nums[i], nums[i - 1]); 
                }
            }
            if (check(nums)) {
                return true;
            }
            k++;
        }
        return false;
    }
};