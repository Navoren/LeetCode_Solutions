class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int temp = x%10; //123 -> 3
            if( ans > INT_MAX /10 || (ans == INT_MAX /10 && temp > 7)) return 0;
            if( ans < INT_MIN / 10 || (ans == INT_MIN/10) && temp <-8) return 0;
            ans = ans*10+temp;
            x /= 10;
        }
        return ans;
    }
};