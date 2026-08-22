class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        long long digitProduct = 1;
        int temp = n;
        
        while (temp > 0) {
            int d = temp % 10;
            digitSum += d;
            digitProduct *= d;
            temp /= 10;
        }
        
        long long total = digitSum + digitProduct;
        return n % total == 0;
    }
};