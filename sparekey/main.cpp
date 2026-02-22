#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e5+5;

int n;
vector<int> adj[mxN];
vector<int> radj[mxN];
bool vis[mxN];
stack<int> stk;
int label;
int scc[mxN];

vector<int> dag_adj[mxN];
int in[mxN];
int sz[mxN];
int nrem[mxN];

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
    stk.push(u);
}

void dfs2(int u) {
    vis[u] = 1;
    scc[u] = label;
    for (int v : radj[u]) {
        if (vis[v]) continue;
        dfs2(v);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v, --v;
            adj[i].push_back(v);
            radj[v].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs(i);
    }
    memset(vis, 0, sizeof vis);
    while (stk.size()) {
        int tp = stk.top();
        stk.pop();
        if (!vis[tp]) {
            dfs2(tp);
            ++label;
        }
    }

    for (int u = 0; u < n; ++u) {
        for (int v : radj[u]) {
            if (scc[u] != scc[v]) {
                dag_adj[scc[u]].push_back(scc[v]);
                ++in[scc[v]];
            }
        }
        ++nrem[scc[u]];
        ++sz[scc[u]];
    }

    queue<int> q;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u, --u;

        if (!--nrem[scc[u]]) {
            // cout << "Ok scc got wrecked" << endl;
            if (in[scc[u]] == 0) {
                q.push(scc[u]);
            }
        }

        while (q.size()) {
            int u = q.front();
            q.pop();
            ans += sz[u];
            for (int v : dag_adj[u]) {
                if (!--in[v] && !nrem[v]) {
                    q.push(v);
                }
            }
        }

        cout << ans << " ";
    }
    cout << endl;
}
