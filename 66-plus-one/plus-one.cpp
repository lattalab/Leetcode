class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (int last = digits.size() - 1; last >= 0; last--) {
            // pruning
            if (!carry) break;
            // carry
            digits[last] = (digits[last] + 1 == 10) ? 0 : digits[last] + 1;
            // propagate carry
            carry = (digits[last] == 0) ? 1 : 0;
        }
        // add 1 one more digits
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};