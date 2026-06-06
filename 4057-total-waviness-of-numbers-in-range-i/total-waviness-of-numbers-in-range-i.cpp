class Solution {
public:
    int waviness(int num) {
        vector<int> digit;
        while (num) {
            digit.push_back(num%10);
            num /= 10;
        }
        int ans = 0;
        for (int i=1; i<digit.size()-1; i++) {
            if (digit[i-1] > digit[i] && digit[i+1] > digit[i]) {
                ans++;
            }
            if (digit[i-1] < digit[i] && digit[i+1] < digit[i]) {
                ans++;
            }
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i=num1; i<=num2; i++) {
            ans += waviness(i);
        }
        return ans;
    }
};