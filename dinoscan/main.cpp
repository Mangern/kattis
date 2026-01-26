#include <bits/stdc++.h>
#include <ios>
using namespace std;

const int mxN = 21;

int n, c1, c2;
int **scan1;
int **scan2;

int area[mxN][2*mxN];

bool check(int place) {
    for (int i = 0; i < n; ++i) {
        memset(area[i], 0, sizeof area[i]);
        for (int j = 0; j < c1; ++j) {
            area[i][j] = scan1[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < c2; ++j) {
            area[i][place+j] += scan2[i][j];
        }
    }

    int mini = n, maxi = -1, minj = 2 * mxN, maxj = -1;

    int num = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < place + c2; ++j) {
            if (area[i][j] > 1) {
                return false;
            } else if (area[i][j] == 1) {
                mini = min(mini, i);
                minj = min(minj, j);
                maxi = max(maxi, i);
                maxj = max(maxj, j);
                ++num;
            }
        }
    }
    int expect;
    if (mini > maxi) expect = 0;
    else expect = (maxi - mini + 1) * (maxj - minj + 1);
    return expect == num;
}

int leftshift(int **grid, int c) {
    int minj = mxN, maxj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j]) {
                minj = min(minj, j);
                maxj = max(maxj, j);
            }
        }
    }
    if (minj == 0) {
        return c;
    }
    int nc = (maxj - minj + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < nc; ++j) {
            grid[i][j] = grid[i][minj + j];
            grid[i][minj+j] = 0;
        }
    }
    return nc;
}

int main() {
    cin >> n >> c1 >> c2;

    scan1 = new int*[mxN];
    scan2 = new int*[mxN];
    for (int i = 0; i < mxN; ++i) {
        scan1[i] = new int[mxN];
        scan2[i] = new int[mxN];
    }

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < c1; ++j) { 
            scan1[i][j] = s[j] == '1';
        }
    }
    c1 = leftshift((int**)scan1, c1);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < c2; ++j) { 
            scan2[i][j] = s[j] == '1';
        }
    }
    c2 = leftshift((int**)scan2, c2);

    for (int j = 0; j <= c1; ++j) {
        if (check(j)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
