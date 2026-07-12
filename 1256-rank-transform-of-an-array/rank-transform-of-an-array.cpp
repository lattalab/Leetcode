class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // sorting
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        // hash map
        int rank = 1;
        unordered_map<int, int> mp;
        for (int i=0; i<temp.size(); i++) {
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = rank;
                rank++;
            }
        }
        // assign rank to original array
        for (int i=0; i<arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};