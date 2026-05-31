class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long int target = mass;
        for (int i=0; i<asteroids.size(); i++) {
            if (target >= asteroids[i]) {
                target += asteroids[i];
            }
            else {
                return false;
            }
        }
        return true;
    }
};