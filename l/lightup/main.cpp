#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &s : grid)cin >> s;
    vector<ii> bulb;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') continue;
            if (grid[i][j] == 'X') continue;
            if (grid[i][j] == '?') { bulb.push_back({i,j}); continue; }
            int need = grid[i][j]-'0';
            int have=0;
            for (auto [ni, nj] : vector<ii>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
                if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                have += grid[ni][nj] == '?';
            }

            if (have != need) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    vector<vector<bool>> lit(n, vector<bool>(n, 0));

    for (auto [bi, bj] : bulb) {
        for (auto [di, dj] : vector<ii>{{-1,0},{1,0},{0,-1},{0,1}}) {
            int i = bi + di;
            int j = bj + dj;

            while (0 <= i && i < n && 0 <= j && j < n) {
                if (grid[i][j] == '?') {
                    cout << 0 << endl;
                    return 0;
                }
                if (grid[i][j] != '.') break;
                lit[i][j] = 1;

                i += di;
                j += dj;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.' && !lit[i][j]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
}
