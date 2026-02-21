class Solution {
public:
    int checkPrime(int num) {
        if (num == 1 || num == 0)
            return 0;

        for (int i=2; i*i <= num; i++) {
            if (num % i == 0)
                return 0;
        }
        return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i=left; i<=right; i++) {
            // C++ useful function depend on compiler -> O(1)
            int bits = __builtin_popcount(i);
            ans += checkPrime(bits);
        }
        return ans;
    }
};