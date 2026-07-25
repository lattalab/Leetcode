class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        while (n) {
            v.emplace_back(n%10);
            n /= 10;
        }

        int ans = -INT_MAX;
        for (int i=0; i<v.size(); i++) {
            for (int j=i+1; j<v.size(); j++) {
                ans = max(ans, v[i]*v[j]);
            }
        }
        return ans;
    }
};