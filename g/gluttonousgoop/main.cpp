#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int OFF = 100;

string grid[2 * OFF];

int main() {
    for (int i = 0; i < 2 * OFF; ++i) {
        grid[i] = string(2 * OFF, '.');
    }

    int n, m, k;
    cin >> n >> m >> k;
    ll pchg = 0;
    ll chg = 0;
    ll pcnt = 0;
    uint64_t cnt = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < m; ++j) {
            grid[OFF+i][OFF+j] = s[j];
            if (s[j] == '#')++cnt;
        }
    }
    if (!cnt) {
        cout << 0 << endl;
        return 0;
    }
    int its;
    for (its = 0; its < min(40, k); ++its) {
        vector<pair<int,int>> add;
        for (int i = 0; i < 2 * OFF; ++i) {
            for (int j = 0; j < 2 * OFF; ++j) {
                if (grid[i][j] == '#') {
                    bool isp = 0;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            add.emplace_back(i+di, j+dj);

                            // if ((di == 0 || dj == 0) && grid[i+di][j+dj] == '.') {
                            //     isp = 1;
                            // }
                        }
                    }
                }
            }
        }
        for (auto [i, j] : add)grid[i][j] = '#';

        pcnt = cnt;
        cnt = 0;
        for (int i = 0; i < 2 * OFF; ++i) {
            for (int j = 0; j < 2 * OFF; ++j) {
                if (grid[i][j] == '#')++cnt;
            }
        }
        pchg = chg;
        chg = cnt - pcnt;
    }
    ll delta = chg - pchg;
    for (; its < k; ++its) {
        chg += delta;
        cnt += (uint64_t)chg;
    }
    cout << cnt << endl;
}
