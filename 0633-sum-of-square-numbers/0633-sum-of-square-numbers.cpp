class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 2; i*i <= c; i++){
            int powerCnt = 0;
            while(c % i == 0){
                powerCnt++;
                c/= i;
            }
            if(i%4 == 3 && powerCnt % 2 != 0) return false;
        }
        return c%4 != 3;
    }
};