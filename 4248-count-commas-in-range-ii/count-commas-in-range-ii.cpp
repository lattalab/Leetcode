class Solution {
public:
    long long countCommas(long long n) {
        // 4:1, 7:2, 10:3, 13:4, 15:5
        // [1e3, 1e6-1], 2[1e6, 1e9-1], 3[1e9, 1e12-1], 4[1e12, 1e15-1], 5[1e15]
        long long ans = 0;
        if (n >= 1000LL) {
            ans += min(n, 999'999LL) - 1000LL + 1;
        }
        if (n >= 1'000'000LL) {
            ans += 2 * (min(n, 999'999'999LL) - 1'000'000LL + 1);
        }
        if (n >= 1'000'000'000LL) {
            ans += 3 * (min(n, 999'999'999'999LL) - 1000'000'000LL + 1);
        }
        if (n >= 1'000'000'000'000LL) {
            ans += 4 * (min(n, 999'999'999'999'999LL) - 1'000'000'000'000LL + 1);
        }

        if (n >= 1'000'000'000'000'000LL) {
            ans += 5;
        }
        
        return ans;
    }
};