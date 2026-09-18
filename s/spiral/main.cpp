#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int mxN = 2e5+5;

bool isp[mxN];
ii pos[mxN];
ii dir[4] = {
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 0}
};

void sieve() {
    memset(isp, 1, sizeof isp);
    isp[0] = isp[1] = 0;
    for (ll i = 2; i < mxN; ++i) {
        if (!isp[i]) continue;
        for (ll j = i * i; j < mxN; j += i) {
            isp[j] = false;
        }
    }
}

int search(const vector<vector<bool>>& grid, int si, int sj, int ti, int tj) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[si][sj] = 0;
    queue<ii> q;
    q.push({si, sj});

    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        for (auto [ni, nj] : vector<ii>{{i-1,j},{i,j-1},{i+1,j},{i,j+1}}) {
            if (ni < 0 || n <= ni || nj < 0 || m <= j) continue;
            if (grid[ni][nj]) continue;
            if (dist[ni][nj] == -1) {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
    return dist[ti][tj];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    sieve();
    vector<ii> loc;

    int step = 1;
    ii cur = {0, 0};
    int d = 0;
    int j = 0;
    int cnt = 0;
    int mini = 10000, maxi = -10000, minj = 10000, maxj = -10000;
    for (int num = 1; num < mxN; ++num) {
        if (isp[num]) {
            loc.push_back(cur);
        }
        pos[num] = cur;
        mini = min(mini, cur.first);
        maxi = max(maxi, cur.first);
        minj = min(minj, cur.second);
        maxj = max(maxj, cur.second);

        cur.first += dir[d].first;
        cur.second += dir[d].second;
        if (++j == step) {
            d++;
            d %= 4;
            j = 0;
            if (++cnt == 2) {
                cnt = 0;
                ++step;
            }
        }
    }


    vector<vector<bool>> grid(maxi - mini + 1, vector<bool>(maxj - minj + 1, false));
    for (auto [i, j] : loc) {
        grid[i-mini][j-minj] = 1;
    }

    int tc = 0;
    for (;;) {
        ++tc;
        int s, t;
        if (!(cin >> s)) break;
        cin >> t;

        cout << "Case " << tc << ": ";

        if (isp[s] || isp[t]) {
            cout << "impossible\n";
            continue;
        }

        auto [si, sj] = pos[s];
        auto [ti, tj] = pos[t];
        si -= mini;
        sj -= minj;
        ti -= mini;
        tj -= minj;

        int ret = search(grid, si, sj, ti, tj);

        if (ret == -1) {
            cout << "impossible\n";
        } else {
            cout << ret << '\n';
        }
    }
}
