#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e6+6;

ll dist[mxN];
vector<int> adj[mxN];

int main() {
    ll m, n, s0;
    cin >> m >> n >> s0;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    for (ll s = 1; s < m; ++s) {
        for (int i = 0; i < n; ++i) {
            ll t = (s * a[i] % m + b[i]) % m;
            adj[t].push_back(s);
        }
    }
    memset(dist,-1, sizeof dist);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dist[s0] << endl;
}
