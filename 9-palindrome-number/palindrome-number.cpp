class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int num = x;
        long reverse = 0;
        while (x) {
            int remainder = x%10;
            reverse = reverse * 10 + remainder;
            x /= 10;
        }
        return num == reverse;
    }
};