#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 5e5+5;

vector<int> adj[mxN];
ll a[mxN];
int in[mxN];

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i], --a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v); ++in[v];
    }
    queue<int> q;
    for (int i = 0; i< n; ++i) {
        if (!in[i])q.push(i);
    }
    ll ans = 0;

    while (q.size()) {
        int u = q.front();
        q.pop();
        ll diff = (k - 1) - a[u];
        ans += diff;
        for (int v: adj[u]) {
            a[v] = (a[v] + diff) % k;
            if (!--in[v]) {
                q.push(v);
            }
        }
    }
    cout << ans << endl;
}
