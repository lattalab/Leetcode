class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        int xClosest;
        if (xCenter < x1) {
            xClosest = x1;
        }
        else if (xCenter > x2) {
            xClosest = x2;
        }
        else {
            xClosest = xCenter;
        }

        int yClosest;
        if (yCenter < y1) {
            yClosest = y1;
        }
        else if (yCenter > y2) {
            yClosest = y2;
        }
        else {
            yClosest = yCenter;
        }

        int dx = xCenter - xClosest;
        int dy = yCenter - yClosest;

        return pow(dx, 2) + pow(dy, 2) <= pow(radius, 2);
    }
};