class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());   // ascending order
        // space complexity to store each absolute distance.
        vector<int> dist;
        int MIN = abs(arr[1] - arr[0]);
        for (int i=0; i<arr.size() - 1; i++) {
            int temp = abs(arr[i+1] - arr[i]);
            dist.push_back(temp);
            MIN = min(MIN, temp);
        }
        // store the minimum absolute value pairs into result
        vector<vector<int>> result;
        for (int i=0; i<dist.size(); i++) {
            if (dist[i] == MIN) {
                result.push_back( {arr[i], arr[i+1]} );
            }
        }
        return result;
    }
};