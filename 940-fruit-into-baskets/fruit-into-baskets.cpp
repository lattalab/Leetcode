class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int, int> mp;   // basket at most 2
        int size = fruits.size();   // check for boundary
        int left = 0, right = 0;
        while (right < size) {
            mp[fruits[right]]++;
            while (mp.size() > 2) {
                // restore the collected fruits
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};