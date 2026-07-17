class Solution {
public:
    bool isVowel (char ch) {
        // detect if this vowel character
        string vowels = "aeiouAEIOU";
        return vowels.find(ch) != string::npos;
    }
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            // update the pointer
            while (left < right && !isVowel(s[left])) left++;
            while (left < right && !isVowel(s[right])) right--;

            swap(s[left], s[right]);
            // update pointer after swap
            left++; right--;
        }
        return s;
    }
};