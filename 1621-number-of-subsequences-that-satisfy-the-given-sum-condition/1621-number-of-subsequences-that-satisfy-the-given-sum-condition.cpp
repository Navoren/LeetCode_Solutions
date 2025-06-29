
class Solution {
public:
    int mod = 1e9 + 7;
    int power(int base, int exp) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        int ct = 0;

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                ct = (ct + power(2, j - i)) % mod;
                i++;
            } else {
                j--;
            }
        }
        return ct;
    }
};