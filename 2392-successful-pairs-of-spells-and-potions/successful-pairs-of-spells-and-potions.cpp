class Solution {
public:
    int binary_search(vector<int> &arr, long long target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)arr[mid] >= target) {
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int i=0; i<spells.size(); i++) {
            long long int target = (success + spells[i] - 1) / spells[i];
            int idx = binary_search(potions, target);
            ans.push_back(potions.size() - idx);
        }
        return ans;
    }
};