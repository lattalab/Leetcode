class Solution {
    struct point {
        int x, y;
        int h, g, f;    // f = g + h
        bool operator < (const point &a) const {
            return a.f < f;
        }
    };

    int heuristic(const point &a, const point &b) {
        return max(abs(a.x-b.x), abs(a.y-b.y));
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();   
        if(grid[0][0] || grid[n-1][n-1])
            return -1;

        struct point end;
        end.x = n-1;
        end.y = n-1;

        vector<vector<bool>> visited(n, vector<bool>(n, false)); 
        priority_queue<point> pq;
        struct point start;
        start.x = 0;
        start.y = 0;
        start.g = 1;
        start.h = heuristic(start, end);
        start.f = start.g + start.h;
        if (!grid[0][0]) {
            pq.push(start);
        }

        int dir[8][2] = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0},
            {1, 1}, {1,-1}, {-1, 1}, {-1, -1}
        };

        while (!pq.empty()) {
            point cur = pq.top();
            pq.pop();

            if (visited[cur.x][cur.y]) continue;

            visited[cur.x][cur.y] = true;

             if (cur.x == n-1 && cur.y == n-1) 
                return cur.g ;

            struct point next;
            for (int i=0; i<8; i++) {
                next.x = cur.x + dir[i][0];
                next.y = cur.y + dir[i][1];

                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) continue;

                if (!grid[next.x][next.y]) {
    
                    next.g = cur.g + 1;
                    next.h = heuristic(end, next);
                    next.f = next.g + next.h;
                    
                    pq.push(next);
                }
            }
        }

        return -1;
    }
};