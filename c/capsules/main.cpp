#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;


const int mxN = 8;

int n, m;
int grid[mxN][mxN];
vector<ii> cells;
int who[mxN][mxN];
ll have[mxN*mxN];
int sz[mxN*mxN];

void search(int idx) {
    if (idx >= cells.size()) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << grid[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0);
    }
    auto [r, c] = cells[idx];

    ll around = 0;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            int ni = r + di, nj = c + dj;
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (!grid[ni][nj]) continue;
            around |= (1LL<<grid[ni][nj]);
        }
    }
    int ar = who[r][c];

    for (int num = 1; num <= sz[ar]; ++num) {
        if ((have[ar] >> num) & 1) continue;
        if ((around >> num) & 1) continue;

        grid[r][c] = num;
        have[ar] ^= (1LL<<num);
        search(idx+1);
        have[ar] ^= (1LL<<num);
        grid[r][c] = 0;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '-') {
                cells.emplace_back(i, j);
            } else {
                grid[i][j] = c - '0';
            }
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; ++j) {
            string s;
            cin >> s;
            char rc = s[1];
            char cc = s[3];
            int r = rc - '1';
            int c = cc - '1';
            if (grid[r][c]) {
                have[i] |= 1LL << (grid[r][c]);
            }
            who[r][c] = i;
            ++sz[i];
        }
    }

    search(0);
}
