class Solution {
public:
    int longestBalanced(string s) {
        int length = s.size();
        int ans = 0;
        for (int start=0; start<length; start++) {
            //using set for recording occurance of letters
            int cnt[26] = {0};
            int unique = 0;
            int count = 0;
            for (int end=start; end<length; end++) {
                // update hash table
                int idx = s[end]-'a';
                cnt[ idx ]++;
                // unique of character
                if ( cnt[idx] == 1 ) {
                    unique++;
                }
                // store the maximum frequency number
                count = max(count, cnt[idx]);
                
                if ( (count*unique) == (end-start+1) ) {
                    ans = max(ans, end-start+1);
                }
            }
        }
        return ans;
    }
};