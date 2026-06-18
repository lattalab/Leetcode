class Solution {
public:
    double angleClock(int hour, int minutes) {
        // for hour: 60 min -> 5 (1/12 speed)
        // gap between hour and minute, and /divide 60 and multiply 360
        const double speed = 5/60.0;
        double start = hour * 5 % 60 + speed * minutes;
        double end = minutes;
        double angle = (double)abs(start-end) / 60.0 * 360;
        return min(angle, 360.0-angle);
    }
};