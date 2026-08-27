#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int mxN = 1005;

int n, m;
vi adj[mxN];
int in[mxN];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++in[v];
    }

    queue<int> q;

    for (int u = 0; u < n; ++u) if (!in[u]) {
        q.push(u);
    }

    vi topo;

    while (q.size()) {
        if (q.size() > 1) {
            cout << "back to the lab" << endl;
            return 0;
        }

        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) if (--in[v] == 0) {
            q.push(v);
        }
    }

    if (topo.size() != n) {
        cout << "back to the lab" << endl;
        return 0;
    }

    for (int u : topo) cout << u << " ";
    cout << endl;
}
