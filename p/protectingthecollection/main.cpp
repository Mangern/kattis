#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 2>;

const int mxN = 2005;

int n, tr, sc;

// urdl
// r,c,dir,inst.
int dp[mxN][mxN][4][2]; // 0:unset,1:open,2:can,3:cannot

string grid[mxN];

ii dir[4] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};

int solve(int i, int j, int d, int inst) {
    if (i == tr && j == n) return 2;

    if (i < 0 || n <= i || j < 0 || n <= j) return 3;
    int& r = dp[i][j][d][inst];

    if (r>1)return r;
    if (r==1) return r = 3;

    r = 1;

    int nd;
    if (grid[i][j] == '.') {
        nd = d;
    } else if (grid[i][j] == '/') {
        switch (d) {
            case 0:
                nd = 1;
                break;
            case 1:
                nd = 0;
                break;
            case 2:
                nd = 3;
                break;
            case 3:
                nd = 2;
                break;
        }
    } else if (grid[i][j] == '\\') {
        switch (d) {
            case 0:
                nd = 3;
                break;
            case 1:
                nd = 2;
                break;
            case 2:
                nd = 1;
                break;
            case 3:
                nd = 0;
                break;
        }
    }

    int ni = i + dir[nd][0];
    int nj = j + dir[nd][1];

    int re = solve(ni, nj, nd, inst);
    if (re == 2) return r = 2;

    if (!inst && grid[i][j] == '.') {
        if (d == 1 || d == 3) {
            re = solve(i-1, j, 0, 1);
            if (re == 2) return r = 2;
            re = solve(i+1, j, 2, 1);
            if (re == 2) return r = 2;
        } else {
            re = solve(i, j+1, 1, 1);
            if (re == 2) return r = 2;
            re = solve(i, j-1, 3, 1);
            if (re == 2) return r = 2;
        }
    }

    return r = 3;
}

int main() {
    cin >> n >> sc >> tr, --sc, --tr;

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        char c;
        cin >> c;
        grid[i].push_back(c);
    }

    cout << (solve(0, sc, 2, 0) == 2 ? "YES" : "NO") << endl;
}
