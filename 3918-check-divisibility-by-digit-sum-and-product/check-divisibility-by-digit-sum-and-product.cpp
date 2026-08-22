class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n%10);
            n /= 10;
        }
        return sum;
    }
    int digitProd(int n) {
        int prod = 1;
        while (n) {
            prod *= (n%10);
            n /= 10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        int sum = digitSum(n);
        int prod = digitProd(n);
        return n % (sum + prod) == 0;
    }
};