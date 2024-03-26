#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5+5;

constexpr int UNVISITED = 0;
constexpr int VISITING = 1;
constexpr int VISITED = 2;

int n, m;
set<int> adj[mxN];
vector<array<int,2>> ans;

int vis[mxN];
int p[mxN];
bool cycle_found;

void dfs_rem_cycle(int u, int cf) {
    if (vis[u] == VISITING) {
        // Found cycle
        int ptr = u;

        //cout << "Cycle: ";

        do {
            ans.push_back({ptr, p[ptr]});
            adj[ptr].erase(p[ptr]);
            adj[p[ptr]].erase(ptr);
            //cout << ptr << ", ";
            ptr = p[ptr];
        } while (ptr != u);
        //cout << endl;

        cycle_found = true;
        return;
    }

    vis[u] = VISITING;

    for (int v : adj[u]) if (v != cf) {
        if (vis[v] != VISITED) {
            p[v] = u;
            dfs_rem_cycle(v, u);
            if (cycle_found) {
                vis[u] = UNVISITED;
                return;
            }
        }
    }
    vis[u] = VISITED;
}

bool rem_cycle(int u) {
    cycle_found = false;
    dfs_rem_cycle(u, -1);
    return cycle_found;
}

void tree_search(int u, int cf = -1, bool up = false) {
    vis[u] = VISITED;
    for (int v : adj[u]) if (v != cf) {
        if (up) {
            ans.push_back({v, u});
        } else {
            ans.push_back({u, v});
        }

        tree_search(v, u, up);

        up = !up;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    int n_odd = 0;
    for (int i = 0; i < m; ++i) {
        int u ,v;
        cin >> u >> v;

        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() & 1)++n_odd;
    }

    for (int i = 1; i <= n; ++i) {
        while (rem_cycle(i)) {}
    }

    /*
    cout << "remaingin: " << endl;
    for (int i = 1; i <= n; ++i) {
        for (auto j : adj[i])cout << i << " " << j << endl;
    }

    cout << endl;
    */

    for (int i = 1; i <= n; ++i)if (adj[i].size())vis[i] = UNVISITED;

    for (int i = 1; i <= n; ++i) {
        if (vis[i] == UNVISITED)tree_search(i);
    }

    cout << n_odd << endl;

    for (auto [u, v] : ans)cout << u << " " << v << endl;

    return 0;
}
