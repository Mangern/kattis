#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

using ii = array<ll, 2>;
using tup = array<ll, 3>;

const int mxN = 105;

const ll INF = 1e9;

int n, m;
ll s;
ll grid[mxN][mxN];

int main() {
    cin >> n >> m >> s;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] > s) {
        cout << -1 << endl;
        return 0;
    }

    // dist[i][x] = min distance to node i with sum of cells == x
    vector<vector<ll>> dist(n * m, vector<ll>(s + 1, INF));

    dist[0][grid[0][0]] = 0;

    priority_queue<tup, vector<tup>, greater<tup>> pq;
    pq.push({0, grid[0][0], 0});

    while (pq.size()) {
        auto [d, x, u] = pq.top();
        pq.pop();

        if (dist[u][x] < d) continue;

        int i = u / m;
        int j = u % m;

        for (auto [ni, nj] : vector<ii>{{i-1,j},{i,j-1},{i+1,j},{i,j+1}}) {
            if (ni < 0 || n <= ni || nj < 0 || m <= nj) continue;

            ll y = x + grid[ni][nj];
            int v = ni * m + nj;
            if (y > s) continue;
            if (d + 1 < dist[v][y]) {
                dist[v][y] = d + 1;
                pq.push({dist[v][y], y, v});
            }
        }
    }

    ll ans = *min_element(begin(dist[n * m - 1]), end(dist[n * m - 1]));

    if (ans == INF) ans = -1;
    cout << ans << endl;
}
