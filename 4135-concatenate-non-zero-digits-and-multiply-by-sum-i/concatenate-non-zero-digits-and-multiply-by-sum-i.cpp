class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        string str = to_string(n);
        for (int i=0; i<str.size(); i++) {
            int temp = (str[i] - '0');
            if (temp == 0) continue;
            x = x*10 + temp;
            sum += temp;
        }
        return x * sum;
    }
};