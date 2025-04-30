class Solution {
private:
int countDigit(int num){
    int count;
    while(num > 0){
    num = num / 10;
    count++;
    }
    return count;
}
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i =0; i<n; i++){
            if(countDigit(nums[i]) % 2 == 0) ans++;
        }
        return ans;
    }
};