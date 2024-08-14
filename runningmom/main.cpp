#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using vi = vector<int>;
const int mxN = 5005;
int n, m, t;
vi adj[mxN];
int vis[mxN];
map<string,int> id;

bool dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 1)return true;
        if (!vis[v]) {
            bool b = dfs(v);
            if (b)return b;
        }
    }
    vis[u] = 2;
    return 0;
}

int main() {
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;

        if (!id.count(a))id[a] = t++;
        if (!id.count(b))id[b] = t++;

        adj[id[a]].push_back(id[b]);
    }

    string s;
    while (cin >> s) {
        memset(vis, 0, sizeof vis);
        cout << s << " " << (dfs(id[s]) ? "safe" : "trapped") << endl;
    }
}
