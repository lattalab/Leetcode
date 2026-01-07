class Solution {
public:
    int ExpandFromCenter(string &s, int left, int right){
        int count =0;
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0;
        for (int i=0; i<s.size(); i++){
            // expand odd length
            count += ExpandFromCenter(s, i, i);
            // expand even length
            count += ExpandFromCenter(s, i, i+1);
        }
        return count;
    }
};