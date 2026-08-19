class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a > 0 || b > 0 || c > 0) {
            int target = c & 1;
            int bit_a = (a & 1);
            int bit_b = (b & 1);
            int op = bit_a | bit_b;
            cout << bit_a << " " << bit_b << " " << target << endl;
            if (op == 0 && target == 1) {
                ans += 1;
            }
            else if (op == 1 && target == 0) {
                // two case: (1, 1, 0) and (1, 0, 0)
                ans += (bit_a + bit_b);
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return ans;
    }
};