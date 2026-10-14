class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        char digit[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int digitSum = 0;
        string result = "";
        for (int i=0; i<num; i++) {
            for (int j=9; j>=0; j--) {
                int d = digit[j] - '0';
                if (digitSum + d > sum) {
                    continue;
                }
                else {
                    digitSum += d;
                    result += digit[j];
                    break;
                }
            }
        }
        return (digitSum == sum) ? result : "";
    }
};