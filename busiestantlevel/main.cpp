#include <bits/stdc++.h>
using namespace std;

int n;
const int mxN = 1e5+5;

vector<int> adj[mxN];
int cnt[mxN];

void dfs(int u, int cf, int d) {
    ++cnt[d];
    for (int v : adj[u]) if (v != cf) {
        dfs(v, u, d + 1);
    }
}

int main() {
    cin >> n;for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, 0);
    cout << max_element(cnt, cnt+n)-cnt << endl;
}
