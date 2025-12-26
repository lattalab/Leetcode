#include <stdlib.h>
#include <string.h>

// LeetCode C function signature
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);

    // allocate rows pointers
    int **ans = (int **)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++){
        // allocate each row and zero-initialize it so ans[..][..] default is 0
        ans[i] = (int*)calloc(n, sizeof(int)); // calloc 會把記憶體設為 0
        (*returnColumnSizes)[i] = n;
    }

    // direction array: right, down, left, up
    int dirR[4] = {0, 1, 0, -1};
    int dirC[4] = {1, 0, -1, 0};

    int r = 0, c = 0, dir = 0;
    for (int num = 1; num <= n * n; num++) {
        ans[r][c] = num;

        int nr = r + dirR[dir];
        int nc = c + dirC[dir];

        // turn direction when boundary or already filled (ans[nr][nc] != 0)
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || ans[nr][nc] != 0) {
            dir = (dir + 1) % 4;  // next direction
            nr = r + dirR[dir];
            nc = c + dirC[dir];
        }

        r = nr;
        c = nc;
    }
    return ans;
}