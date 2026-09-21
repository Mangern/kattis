#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

const int mxN = 100 * 100 + 10;

void solve() {
    bitset<mxN> rem;

    int n, m;
    cin >> n >> m;

    vector<string> grid(n, string(m, '.'));

    int p, w;
    cin >> p;
    vector<ii> pts;

    for (int k = 0; k < p; ++k) {
        int i, j;
        cin >> i >> j, --i, --j;
        grid[i][j] = '*';
        pts.push_back({i, j});
        rem.set(i * m + j);
    }
    cin >> w;
    for (int k = 0; k < w; ++k) {
        int i, j;
        cin >> i >> j, --i, --j;
        grid[i][j] = '#';
    }

    vector<bitset<mxN>> moves;

    for (auto [si, sj] : pts) {
        bitset<mxN> mv;
        for (int i = si; i < n; ++i) {
            if (grid[i][sj] == '#') break;
            if (grid[i][sj] == '*') {
                mv.set(i * m + sj);
            }
        }
        moves.push_back(mv);
        mv.reset();
        for (int j = sj; j < m; ++j) {
            if (grid[si][j] == '#') break;
            if (grid[si][j] == '*') {
                mv.set(si * m + j);
            }
        }
        moves.push_back(mv);
    }

    int ans = 0;
    while (rem.count() > 0) {
        int best_count = 0;
        bitset<mxN> best_move;
        for (const auto& mv : moves) {
            auto effect = mv & rem;
            int cnt = effect.count();
            if (cnt > best_count) {
                best_count = cnt;
                best_move = effect;
            }
        }
        ++ans;
        rem ^= best_move;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        solve();
    }
}
