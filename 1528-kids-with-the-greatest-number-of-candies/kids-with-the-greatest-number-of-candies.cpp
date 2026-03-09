class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int max = 0;
        for(int i=0; i<n; i++) {
            if (candies[i] > max) {
                max = candies[i];
            }
        }
        // see if largest among others
        vector<bool> results(n, false);
        for (int i=0; i<n; i++) {
            if (candies[i] + extraCandies >= max) {
                results[i] = true;   
            }
        }
        return results;
    }
};