#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;

const int mxN = 1005;

int n, k, c;

// the 
int ltime[mxN];
vector<int> adj[11][mxN];

bool vis[mxN];

vector<int> sim(int pat) {
    // assume pat starts infected
    vector<int> q = {pat};


    for (int i = 1; i <= k; ++i) {
        vector<int> nxt;
        memset(vis, 0, sizeof vis);

        for (int u : q) {
            for (int v : adj[i][u]) {
                if (!vis[v] && ltime[u] <= i) {
                    vis[v] = 1;
                    nxt.push_back(v);
                }
            }
        }
        swap(nxt, q);
    }

    return q;
}

int main() {
    cin >> n >> k >> c;

    for (int i = 0; i < c; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        ltime[u] = max(ltime[u], d);
        ltime[v] = max(ltime[v], d);
        adj[d][u].push_back(v);
        adj[d][v].push_back(u);
    }

    set<int> pos;
    for (int i = 1; i <= n; ++i) {
        if (ltime[i] < 2) {
            auto vec = sim(i);
            for (int j : vec)pos.insert(j);
        }
    }

    cout << pos.size() << endl;
    for (auto p : pos) {
        cout << p << endl;
    }
}
