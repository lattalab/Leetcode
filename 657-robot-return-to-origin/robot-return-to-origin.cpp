class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, pair<int, int>> dir= {
            {'U', {0, 1}},
            {'D', {0, -1}},
            {'R', {1, 0}},
            {'L', {-1, 0}},
        };
        // trace the loop
        int x = 0;
        int y = 0;
        for (int i=0; i<moves.size(); i++) {
            int nx = dir[moves[i]].first;
            int ny = dir[moves[i]].second;
            x += nx;
            y += ny;
        }  
        return (x==0) && (y==0);
    }
};