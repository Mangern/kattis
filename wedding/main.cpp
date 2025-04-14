#include <bits/stdc++.h>
using namespace std;

const int mxN = 150;

int n, m;

vector<int> adj[mxN];
vector<int> radj[mxN];
stack<int> stk;
bool vis[mxN];
int scc[mxN];

char ans[mxN];

int id(string s) {
    char c = s.back();
    int val = stoi(s.substr(0, s.length() - 1));
    return val + n * (c == 'h');
}

int notid(int i) {
    if (i >= 2 * n) return i - 2 * n;
    return i + 2 * n;
}

void dfs1(int u) {
    vis[u] = 1;

    for (int v : adj[u]) if (!vis[v]) {
        dfs1(v);
    }

    stk.push(u);
}

int sccptr;
void dfs2(int u) {
    scc[u] = sccptr;
    vis[u] = 1;

    for (int v : radj[u]) if (!vis[v]) {
        dfs2(v);
    }
}

int main() {
    cin >> n >> m;

    // (a v b)
    //
    // -a -> b
    // -b -> a
    for (int i = 0; i < 4 * n; ++i) {
        adj[i].clear();
        radj[i].clear();
    }

    for (int i = 0; i < m; ++i) {
        string s, t;
        cin >> s >> t;
        int u = id(s);
        int v = id(t);

        adj[notid(u)].push_back(v);
        radj[v].push_back(notid(u));
        adj[notid(v)].push_back(u);
        radj[u].push_back(notid(v));
    }

    for (int i = 0; i < n; ++i) {
        // (-a v -b)
        //
        // a -> -b
        // b -> -a
        int u = i;     // iw
        int v = i + n; // ih
        adj[u].push_back(notid(v));
        radj[notid(v)].push_back(u);
        adj[v].push_back(notid(u));
        radj[notid(u)].push_back(v);
    }

    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 4 * n; ++i) {
        if (!vis[i]) dfs1(i);
    }

    memset(vis, 0, sizeof vis);
    sccptr = 0;
    while (stk.size()) {
        int u = stk.top();
        stk.pop();
        if (vis[u]) continue;
        dfs2(u);
        ++sccptr;
    }

    bool f = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (scc[i] == scc[notid(i)]) {
            cout << "bad luck" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (scc[i] > scc[notid(i)]) {
            ans[i] = 'w';
        } else {
            ans[i] = 'h';
        }
    }

    if (ans[0] == 'h') {
        cout << "bad luck" << endl;
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        cout << i << ans[i] << " \n"[i==n-1];
    }
}
