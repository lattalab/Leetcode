class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i=0; i<position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        // decreasing order
        sort(cars.rbegin(), cars.rend());

        // montonic stack
        stack<double> st;
        for (int i=0; i<cars.size(); i++) {
            double time = (double) (target - cars[i].first) / cars[i].second;
            if (st.empty() || st.top() < time) {
                st.push(time);
            }
        }
        return st.size();
    }
};