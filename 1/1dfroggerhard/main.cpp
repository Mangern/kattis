#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 2e5+5;
const int OOB = mxN - 1;

int n;
int adj[mxN];
int val[mxN];
int vis[mxN];
int cf[mxN];
bool incycle[mxN];
ll st_size[mxN];
ll comp_sz[mxN];

int C = 0;
vector<int> cycle[mxN];
vector<int> child[mxN];

unordered_set<int> blocked;
ll ans = 0;

void dfs(int u) {
    vis[u] = 1;

    int v = adj[u];
    if (vis[v] == 2) {
    } else if (vis[v] == 1) {
        // Cycle
        cf[v] = u;
        int x = v;
        do {
            incycle[x] = true;
            cycle[C].push_back(x);
            x = cf[x];
        } while (x != v);
        ++C;
    } else {
        cf[v] = u;
        dfs(v);
    }

    if (!incycle[u]) {
        child[v].push_back(u);
    }

    vis[u] = 2;
}

void dfs_sz(int u) {
    st_size[u] = 1;
    for (int v : child[u]) {
        dfs_sz(v);
        st_size[u] += st_size[v];
    }
}

void dfs_tree(int u) {
    bool was_free = false;
    if (!blocked.count(val[u])) {
        was_free = true;
        blocked.insert(val[u]);
        ans += st_size[u];
    }

    for (int v : child[u]) {
        dfs_tree(v);
    }

    if (was_free) {
        blocked.erase(val[u]);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i + val[i] < 0 || i + val[i] >= n) {
            adj[i] = OOB;
        } else {
            adj[i] = i + val[i];
        }
    }
    adj[OOB] = OOB;
    val[OOB] = OOB;

    /**
     * 1. Find cycles/trees/components
     *    - Compute subtree size for every node
     * 2. For each component:
     *    - Let blocked be an empty set
     * 3. For each node u in the cycle: 
     *    - if val[u] not in blocked: Add component size to val[u]'s answer.
     *    - Add val[u] to the "blocked" set
     *    - Search down the tree.
     *    - If not in blocked: add subtree size to answer. Add it to blocked.
     *    - When exiting: if was added to blocked here, remove it again.
     *
     * What we need to know:
     * - For every component, the list of nodes in its cycle
     * - For every component, its size
     * - For every node, its children in its tree
     * - For every node, its subtree size
     */

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    for (int c = 0; c < C; ++c) {
        for (int u : cycle[c]) {
            dfs_sz(u);
            comp_sz[c] += st_size[u];
        }
    }

    for (int c = 0; c < C; ++c) {
        blocked.clear();
        blocked.insert(val[OOB]);

        for (int u : cycle[c]) {
            if (!blocked.count(val[u])) {
                ans += comp_sz[c];
                blocked.insert(val[u]);
            }
        }
        for (int u : cycle[c]) {
            dfs_tree(u);
        }
    }
    cout << ans << endl;
}
