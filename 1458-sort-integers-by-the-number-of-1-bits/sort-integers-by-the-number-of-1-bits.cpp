class Solution {
public:
    static bool cmp (const pair<int, int> &p1, const pair<int, int> &p2)  {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        // store array size
        int n = arr.size();
        
        vector<pair<int, int>> nums(n);
        for (int i=0; i<n; i++) {
            // count binary 1s
            int x = arr[i];
            int count = 0;
            while (x) {
                count += (x&1);
                x >>= 1;
            }
            // store the current number
            nums[i] = {arr[i], count};
        }

        // sorting into increasing order
        sort(nums.begin(), nums.end(), cmp);
        
        // modify the array sequence
        for (int i=0; i<n; i++) {
            arr[i] = nums[i].first;
        }
        return arr;
    }
};