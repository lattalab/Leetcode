class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int ans = 1; // at least need one shot
        int end = points[0][1];
        for (int i=1; i<points.size(); i++) {
            if (points[i][0] > end) {
                // the interval is not overlap
                ans++;
                // update the new end
                end = points[i][1];
            }
            else {
                end = min(end, points[i][1]);
            }
        }
        return ans;
    }
};