#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const ll INF = numeric_limits<ll>::max() / 4;

const int mxN = 2e5+5;

vector<int> adj[mxN];
vector<int> radj[mxN];
ll rdist[mxN];
ll ans[mxN];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    memset(rdist, -1, sizeof rdist);

    rdist[0] = 0;
    queue<int> q;
    q.push(0);

    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (rdist[v] == -1) {
                rdist[v] = rdist[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ans[i] = INF;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    ans[n-1] = 0;
    pq.push({0, n - 1});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (ans[u] < d) continue;

        for (int v : radj[u]) {
            ll cur = 1 + ans[u];
            cur = max(cur, rdist[v]);
            if (cur < ans[v]) {
                ans[v] = cur;
                pq.push({cur, v});
            }
        }
    }
    for (int i = 0; i < n - 1; ++i)cout << ans[i] << " ";
    cout << endl;
}
