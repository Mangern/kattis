#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    int n;
    cin >> n;

    vector<ii> pts(n);
    for (auto &[x, y] : pts) cin >> x >> y;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<ll> dist(n, numeric_limits<ll>::max() / 4);
    vector<bool> vis(n,0);
    dist[0] = 0;
    pq.push({0,0});

    ll ans = 0;
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;
        ans += 2 * dist[u];
        vis[u] = 1;

        for (int v = 0; v < n; ++v) if (!vis[v]) {
            ll w = abs(pts[u][0] - pts[v][0]) + abs(pts[u][1] - pts[v][1]);
            if (w < dist[v]) {
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << ans << endl;
}
