class Solution {
public:
    bool check (vector<int> &piles, int h, int k) {
        long long int spent = 0;
        for (int i=0; i<piles.size(); i++) {
            spent += (piles[i] + k - 1) / k;
        }
        if (spent <= (long long)h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int MAX = *max_element(piles.begin(), piles.end());
        
        int left = 1;
        int right = MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(piles, h, mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};