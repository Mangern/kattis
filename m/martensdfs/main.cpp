#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int mxN = 1e5+5;

int n,m;
set<int> adj[mxN];
bool vis[mxN];
int t = 0;
vi L;

void dfs(int u) {
    vis[u] = 1;
    while (t < n && adj[u].count(L[t])) {
        adj[u].erase(L[t]);
        dfs(L[t++]);
    }
    for (int v : adj[u]) {
        if (!vis[v]) {
            cout << "NO" << endl;
            exit(0);
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

    dfs(L[t++]);

    for (int i = 0; i < n; ++i)if (!vis[i]) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}
