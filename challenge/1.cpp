#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

int n, m;

int main() {
    cin >> n >> m;

    vector<vi> adj(n);
    vector<vi> radj(n);
    vi in(n, 0);
    
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        ++in[v];
    }

    queue<int> q;
    vi ans;

    for (int i = 0; i < n; ++i) if (!in[i])q.push(i);

    while (q.size()) {
        int u = q.front();
        q.pop();

        ans.push_back(u+1);

        for (auto v : adj[u]) {
            if (!--in[v])q.push(v);
        }
    }

    if (ans.size() < n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto& x : ans)cout << x << "\n";
    }
    return 0;
}
