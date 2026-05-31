class Solution {
public:
    void RemoveExtraSpace (string &s) {
        int slow =0;
        for (int fast = 0; fast < s.size(); fast++) {
            // remove preceding space
            if (s[fast] != ' ') {
                // intermdeia space
                if (slow != 0) s[slow++] = ' ';
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }
    void reverseRange(string &s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        // 1. remove extra space
        RemoveExtraSpace(s);
        // 2. reverse entire string
        reverse(s.begin(), s.end());
        // 3. reverse the word
        int left = 0;
        for (int i=0; i<=s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverseRange(s, left, i-1);
                left = i+1;
            }
        }
        return s;
    }
};