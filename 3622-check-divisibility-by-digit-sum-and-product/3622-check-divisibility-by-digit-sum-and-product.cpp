class Solution {
public:
    int digitSum(int n){
        int digit = 0;
        while(n){
            digit += n%10;
            n/=10;
        }
        return digit;
    }

    int digitProduct(int n){
        int digit = 1;
        while(n){
            digit *= n%10;
            n/=10;
        }
        return digit;
    }    
    bool checkDivisibility(int n) {
        int digiSum = digitSum(n);
        int digiProduct = digitProduct(n);

        int x = digiSum + digiProduct;
        return n % x == 0;
    }
};