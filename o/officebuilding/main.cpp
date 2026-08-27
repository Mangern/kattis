#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 25;

ll n, m, s, t;
ll grid[mxN][mxN];
bool blue[mxN][mxN];
bool nblue[mxN][mxN];

void rot() {
    for (int i = 0; i < mxN; ++i) {
        for (int j = 0; j < mxN; ++j) {
            nblue[i][j] = blue[j][mxN-1-i];
        }
    }
    for (int i = 0; i < mxN; ++i) for (int j = 0; j < mxN; ++j) {
        blue[i][j] = nblue[i][j];
        nblue[i][j] = 0;
    }
}

void fix() {
    int mini = mxN, maxi = 0, minj = mxN, maxj = 0;

    for (int i = 0; i < mxN; ++i) {
        for (int j = 0; j < mxN; ++j) {
            if (blue[i][j]) {
                mini = min(mini,i);
                maxi = max(maxi,i);
                minj = min(minj,j);
                maxj = max(maxj,j);
            }
        }
    }

    int iptr=0;
    for (int i = mini; i <= maxi; ++i) {
        int jptr=0;
        for (int j = minj; j <= maxj; ++j) {
            blue[iptr][jptr++] = blue[i][j];
            blue[i][j] = 0;
        }
        ++iptr;
    }
    s = maxi - mini + 1;
    t = maxj - minj + 1;
}

int main() {
    cin >> n >> m;
    ll sall = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            sall += grid[i][j];
        }
    }

    cin >> s >> t;
    for (int i = 0; i < s; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < t; ++j) {
            blue[i][j] = (str[j] == '#');
        }
    }
    ll ans = 0;
    for (int _ = 0; _ < 4; ++_) {
        rot();
        fix();
        for (int i = 0; i + s - 1 < n; ++i) {
            for (int j = 0; j + t - 1 < m; ++j) {
                ll rem = 0;
                for (int ii = 0; ii < s; ++ii) {
                    for (int jj = 0; jj < t; ++jj) {
                        if (blue[ii][jj])rem += grid[i+ii][j+jj];
                    }
                }
                ans = max(ans, sall - rem);
            }
        }
    }
    cout << ans << endl;
}
