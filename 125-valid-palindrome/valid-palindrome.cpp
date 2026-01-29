class Solution {
public:
    bool isPalindrome(string s) {
        // directly trace from begining and end
        // at the same time, do necessary transformation
        int start =0, end = s.size()-1;
        while (end > start) {
            while ( start < end && !isalnum(s[start]) ) {
                start++;
            }
            while ( end > start && !isalnum(s[end]) ) {
                end--;
            }
            
            if ( tolower(s[start]) != tolower(s[end]) )
                return false;
            
            start++;
            end--;
        }
        return true;
    }
};