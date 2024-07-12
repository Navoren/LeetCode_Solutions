class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int aCount = 0;
        int bCount = 0;
        int lesser = min(x,y);
        int res = 0;

        for(char c: s){
            if(c > 'b'){
                res += min(aCount, bCount) * lesser;
                aCount = 0;
                bCount = 0;
            }
            else if(c == 'a'){
                if (x < y && bCount > 0){
                    bCount--;
                    res += y;
                }
                else{
                    aCount++;
                }
            }
            else{
                if(x > y && aCount > 0){
                    aCount--;
                    res += x;
                }
                else{
                    bCount++;
                }
            }
        }
        res += min(aCount, bCount) * lesser;
        return res;
    }
};