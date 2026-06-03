class Solution {
public:
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2) {
        int n = start1.size();
        int m = start2.size();
        int finish1 = INT_MAX;   // save current last finish time
        for (int i=0; i<n; i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        // check for the next earliest ride
        int finish2 = INT_MAX;
        for (int j=0; j<m; j++) {
            finish2 = min(finish2, max(finish1, start2[j]) + duration2[j]);
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land_water = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};