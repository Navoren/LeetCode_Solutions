class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            // Swap if current number is negative
            if (curr < 0) std::swap(maxProd, minProd);

            maxProd = std::max(curr, maxProd * curr);
            minProd = std::min(curr, minProd * curr);

            result = std::max(result, maxProd);
        }
        return result;
    }
};