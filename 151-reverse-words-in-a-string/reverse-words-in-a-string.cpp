class Solution {
public:
    void removeExtraSpaces (string &s){
        int slow = 0, fast = 0;
        for (fast=0; fast<s.size(); fast++){
            if (s[fast] != ' '){
                // pad an space between words
                if (slow != 0) s[slow++] = ' ';
                // copy entire word
                while (fast < s.size() && s[fast] != ' ')
                    s[slow++] = s[fast++];
            }
        }
        s.resize(slow);
    }
    void reverse(string& s, int start, int end){
        for (int i=start, j=end; i<j; i++, j--){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    string reverseWords(string s) {
        removeExtraSpaces(s); // remove redundent space
        reverse(s, 0, s.size()-1); // reverse entire strings
        int start = 0;
        for(int i=0; i<=s.size(); i++){
            // because the last word need to do reverse by s.size()
            if (s[i] == ' ' || i==s.size()){
                int end = i-1;
                reverse(s, start, end);
                start = i+1;
            }
        }
        return s;
    }
};