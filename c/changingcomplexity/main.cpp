#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 200005;

vector<int> adj[mxN];
int in[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        ++in[v];
    }

    set<int> queue;
    for (int i = 0; i < n; ++i) {
        if (!in[i])queue.insert(i);
    }

    ll ans = 0;
    for (ll it = 1; it <= n; ++it) {
        int u;
        if (it & 1) {
            u = *queue.begin();
            queue.erase(queue.begin());
        } else {
            u = *--queue.end();
            queue.erase(--queue.end());
        }

        ans += it * (ll)(u+1);

        for (int v : adj[u]) {
            if (!--in[v]) {
                queue.insert(v);
            }
        }
    }
    cout << ans << endl;
}
