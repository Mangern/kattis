#include <bits/stdc++.h>
using namespace std;

const int mxN = 105;

int n;
double val[mxN];
vector<int> adj[mxN];

void bfs(int source) {
    using state = pair<int, double>;
    vector<bool> vis(n, false);
    vis[source] = true;

    queue<state> q;
    q.push({source, 1.0});

    while (q.size()) {
        auto [u, prod] = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                double vprod = prod * adj[v].size();
                q.push({v, vprod});
                val[v] += 1.0 / vprod;
            }
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        val[i] = 1.0;
    }
    for (int i = 1; i <= n; ++i) {
        bfs(i);
    }

    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += val[i];
    }
    ans /= n;
    cout << setprecision(9) << fixed << ans << endl;
}
