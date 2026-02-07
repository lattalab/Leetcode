class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int idxA = a.size()-1, idxB = b.size()-1;
        int carry = 0;
        while (idxA >= 0 || idxB >= 0 || carry) {
            int digit = carry;
            // avoid exit boundary
            if (idxA >= 0) digit += (a[idxA] - '0');
            if (idxB >= 0) digit += (b[idxB] - '0');

            result += ((digit%2) + '0');
            carry = digit/2;
            // decrement
            idxA--; idxB--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};