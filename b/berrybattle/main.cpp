#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int mxN = 3e5+5;

int n;

int p[mxN];
vi adj[mxN];
int depth[mxN];
int m_dp;
int lo;
int root;
bool vis[mxN];

void dfs(int u) {
    if (depth[u] > m_dp) {
        m_dp = depth[u];
        lo = u;
    }
    for (int v : adj[u]) if (p[u] != v) {
        p[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

int main() {
    cin >> n;

    for (int i= 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    root = lo;

    memset(depth, 0, sizeof depth);
    memset(p, -1, sizeof p);
    m_dp = 0;

    dfs(root);

    if (m_dp < 3) {
        cout << "NO" << endl;
        return 0;
    }

    int ptr = p[p[lo]];

    queue<int> q;

    vi ans;

    while (true) {
        vis[ptr] = 1;
        ans.push_back(ptr+1);

        for (int u : adj[ptr]) if (!vis[u] && p[ptr] != u) {
            q.push(u);
        }

        if (ptr == root)break;
        ptr = p[ptr];
    }

    while (q.size()) {
        ans.push_back(q.front()+1);
        vis[q.front()] = 1;
        for (int u : adj[q.front()]) if (!vis[u]) {
            q.push(u);
        }
        q.pop();
    }

    cout << "YES" << endl;
    for (auto x : ans)cout << x << " ";
    cout << endl;
    return 0;
}
