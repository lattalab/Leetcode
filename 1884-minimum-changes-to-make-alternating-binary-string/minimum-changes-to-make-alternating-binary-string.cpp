class Solution {
public:
    int minOperations(string s) {
        // starting with final results
        string s0;
        string s1;
        for (int i=0; i<s.size(); i++)  {
            s0 += ( (i%2) == 0 ) ? '0' : '1';
            s1 += ( (i%2) == 0 ) ? '1' : '0';
        }

        // recored the diffenerence
        int count0 = 0, count1 = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] != s0[i]) count0++;
            if (s[i] != s1[i]) count1++;
        }

        // find minimum ans
        return min(count0, count1);
    }
};