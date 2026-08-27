#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 1005;

ll wgt[mxN][mxN];
ll dist[mxN];

int main() {
    int n, s, t;
    cin >> n >> s >> t;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> wgt[i][j];
        }
        dist[i] = 1e12;
    }

    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (int v = 0; v < n; ++v) {
            ll w = wgt[u][v];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[t] << endl;
}
