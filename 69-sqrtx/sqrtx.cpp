class Solution {
public:
    int mySqrt(int x) {
        // edge case
        if (x <= 1) return x;

        int left = 1, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // avoid overflow
            long long square = (long) mid * mid;
            if (square > x)
                right = mid-1;
            else if (square < x)
                left = mid + 1;
            else
                return mid;
        }
        return left - 1;
    }
};