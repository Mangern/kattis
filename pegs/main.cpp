#include <bits/stdc++.h>
using namespace std;

const int mxN = 1<<15;

int dp[mxN];

int di[] = {-1, -1,  0,  0,  1,  1};
int dj[] = {-1,  0, -1,  1,  0,  1};

int oi[] = { 1,  1,  0,  0, -1, -1};
int oj[] = { 1,  0,  1, -1,  0, -1};

int idx[5][5];

int minleft(int state) {
    if (dp[state] != -1) {
        return dp[state];
    }
    int rem = __builtin_popcount(state);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <= i; ++j) {
            if ((state >> idx[i][j]) & 1) {
                for (int dir = 0; dir < 6; ++dir) {
                    int ni1 = i + di[dir];
                    int nj1 = j + dj[dir];
                    int ni2 = i + oi[dir];
                    int nj2 = j + oj[dir];

                    if (ni1 < 0 || ni1 >= 5 || nj1 < 0 || nj1 > ni1) continue;
                    if (ni2 < 0 || ni2 >= 5 || nj2 < 0 || nj2 > ni2) continue;

                    if (!((state >> idx[ni1][nj1])&1)) continue;
                    if ((state >> idx[ni2][nj2])&1) continue;

                    int nxt = state;
                    nxt ^= (1<<idx[ni1][nj1]);
                    nxt ^= (1<<idx[i][j]);
                    nxt ^= (1<<idx[ni2][nj2]);

                    rem = min(rem, minleft(nxt));
                }
            }
        }
    }

    return dp[state] = rem;
}

int main() {
    int state = 0;
    int p = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <= i; ++j) {
            char c;
            cin >> c;
            if (c == 'X') {
                state |= (1<<p);
            }
            idx[i][j] = p;
            ++p;
        }
    }
    memset(dp, -1, sizeof dp);
    dp[0] = 0;

    cout << minleft(state) << endl;
}
