class Solution {
public:
    int digit_prod(int n) {
        int num = 1;
        while (n) {
            num *= (n%10);
            n /= 10;
        }
        return num;
    }
    int smallestNumber(int n, int t) {
        int ans = n;
        for (ans ; digit_prod(ans)%t != 0; ans++) {
            
        }
        return ans;
    }   
};