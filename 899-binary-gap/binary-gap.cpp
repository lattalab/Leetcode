class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int pos = 0;
        int ans = 0;
        while (n) {
            int curr = n & 1;

            if (curr == 1) {
                if (last != -1) {
                    // update ans
                    ans = max(ans, pos - last);
                }
                last = pos;
            }
            pos++;
            n >>= 1;
        }
        
        return ans;
    }
};