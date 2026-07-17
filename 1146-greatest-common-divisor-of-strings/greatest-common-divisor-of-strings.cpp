class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // if we can divide, then we have common pattern repeat n times
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        // apply gcd to find valid answer
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};