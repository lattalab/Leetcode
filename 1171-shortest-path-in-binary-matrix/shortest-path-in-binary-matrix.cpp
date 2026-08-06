class Solution {
    struct point {
        int x, y;
        int g, h, f;

        bool operator < (const point &a) const {
            return f > a.f; // min heap
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


        vector<vector<bool>> visited(
            n,
            vector<bool>(n,false)
        );


        priority_queue<point> pq;


        point start;

        start.x=0;
        start.y=0;
        start.g=1;
        start.h=heuristic(start,{n-1,n-1});
        start.f=start.g+start.h;


        pq.push(start);


        int dir[8][2]={
            {0,1},{1,0},
            {0,-1},{-1,0},
            {1,1},{1,-1},
            {-1,1},{-1,-1}
        };


        while(!pq.empty()){


            point cur=pq.top();
            pq.pop();


            if(visited[cur.x][cur.y])
                continue;


            visited[cur.x][cur.y]=true;


            if(cur.x==n-1 && cur.y==n-1)
                return cur.g;



            for(auto &d:dir){

                point next;

                next.x=cur.x+d[0];
                next.y=cur.y+d[1];


                if(next.x<0 || next.x>=n ||
                   next.y<0 || next.y>=n)
                    continue;


                if(grid[next.x][next.y])
                    continue;


                next.g=cur.g+1;
                next.h=heuristic(next,{n-1,n-1});
                next.f=next.g+next.h;


                pq.push(next);
            }
        }


        return -1;
    }
};