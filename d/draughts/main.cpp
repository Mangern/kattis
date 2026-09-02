#include <bits/stdc++.h>
using namespace std;

const int N = 10;

string grid[N];

bool is_free(int i, int j) {
    return grid[i][j] == '#' || grid[i][j] == '.';
}

int search(int i, int j) {
    assert(grid[i][j] == 'W');

    int ret = 0;
    for (int di = -1; di <= 1; di += 2) {
        for (int dj = -1; dj <= 1; dj += 2) {
            int ni = i + di;
            int nj = j + dj;
            if (ni < 0 || N <= ni || nj < 0 || N <= nj) continue;
            if (grid[ni][nj] != 'B') continue;
            int mi = ni + di;
            int mj = nj + dj;
            if (mi < 0 || N <= mi || mj < 0 || N <= mj) continue;
            if (!is_free(mi, mj)) continue;

            grid[i][j] = '.';
            grid[ni][nj] = '.';
            grid[mi][mj] = 'W';
            ret = max(ret, 1 + search(mi, mj));
            grid[i][j] = 'W';
            grid[ni][nj] = 'B';
            grid[mi][mj] = '.';
        }
    }
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        for (int i = 0; i < N; ++i) {
            cin >> grid[i];
        }

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 'W') {
                    ans = max(ans, search(i, j));
                }
            }
        }
        cout << ans << endl;
    }
}
