class Solution {
public:
    int smallestNumber(int n, int t) {
        while(prodOfDigits(n) % t != 0) n++;
        return n;
    }

    int prodOfDigits(int num){
        int prod = 1;

        while(num){
            prod *= num % 10;
            num/=10;
        }

        return prod;
    }
};