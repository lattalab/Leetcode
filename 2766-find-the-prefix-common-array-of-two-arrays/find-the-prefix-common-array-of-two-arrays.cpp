class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int freq[60] = {0};
        int n = A.size();
        vector<int> ans(n, 0);
        for (int i=0; i<n; i++) {
            // first, count the frequency
            freq[A[i]]++;
            freq[B[i]]++;
            // second if there exist pair, then add 1 to the answers (assume no repetitive)
            for (int j=0; j<=n; j++) {
                if (freq[j] == 2) ans[i]++;
            }
        }
        return ans;
    }
};