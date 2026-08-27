#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int mxN = 1e5+5;

int n,m;
set<int> adj[mxN];
bool vis[mxN];
int t = 0;
vi L;

void dfs(int cf = -1) {
    int u = L[t];

    if (vis[u])return;

    vis[u] = 1;
    if (t == L.size() - 1) {
        return;
    }

    adj[u].erase(cf);

    while (adj[u].size()) {
        if (!adj[u].count(L[t+1])) {
    }

    for (int v : adj[u]) {
        if (t+1 == n)return;
        if (v == L[t+1]) {
            ++t;
            dfs(u);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    string line;
    getline(cin >> ws, line);
    stringstream ss(line);

    string s;
    while (ss >> s)L.push_back(stoi(s));

    set<int> test(begin(L), end(L));
    if (test.size() != n) {
        cout << "NO" << endl;
        return 0;
    }

    dfs();

    for (int i = 0; i < n; ++i)if (!vis[i]) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}
