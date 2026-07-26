class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(int x : arr){
            int rem = ((x % k) + k) % k;
            freq[rem]++;
        }
        if (freq[0] % 2 != 0) return false;
        if (k % 2 == 0 && freq[k / 2] % 2) return false;

        for (int r = 1; r < k; r++) {
            if (r == k - r) continue;
            if (freq[r] != freq[k - r])
                return false;
        }

        return true;
    }
};