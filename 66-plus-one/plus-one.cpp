class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size() - 1;
        bool carry;
        do {
            if (digits[last] + 1 == 10) {
                if (last == 0) {
                    digits.push_back(0);
                    digits[last] = 1;
                }
                else {
                    digits[last] = 0;
                }
            }
            else digits[last] += 1;
            carry = (digits[last] == 0) ? 1 : 0;
            last--;
        } while(carry);
        return digits;
    }
};