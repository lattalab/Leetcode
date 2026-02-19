class Solution {
public:
    double quickPow(double x, long long n) {
        // edge case
        if (n == 0) return 1;
        
        if (n%2 == 0) {
            double res = quickPow(x, n/2);
            return res * res;
        }
        return x * quickPow(x, n-1);
    }
    double myPow(double x, int n) {
        // do positive side
        double ans = quickPow(x, labs((long long)n));
        if (n >= 0)  return ans;
        return 1.0/ans; // negative exp
    }
};