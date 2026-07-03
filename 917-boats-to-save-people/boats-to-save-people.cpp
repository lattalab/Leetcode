class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        
        int i = 0;
        int j = people.size() - 1;
        while (i<=j) {
            int total = people[i] + people[j];
            if (total > limit) {
                ans++;
                j--;
            }
            else {
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
};