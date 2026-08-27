#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

const int mxN = 5e5+6;

int n, m;
vi adj[mxN];
int vis[mxN];
bool root[mxN];
int comp = 0;
int bbpt = 1;

void dfs(int u, int cf = -1, int col = 1) {
    vis[u] = col;
    for (int v : adj[u]) if (v != cf) {
        if (!vis[v]) {
            dfs(v, u, col == 1 ? 2 : 1);
        }
        else if (vis[v] == col) {
            bbpt = 0;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ++comp;
            dfs(i);
        }
    }

    cout << comp - 1 + bbpt << endl;
}
