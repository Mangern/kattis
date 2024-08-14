#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using ii = array<int,2>;

const int mxN = 1e5+5;

int n;
vector<int> adj[mxN];
int us[mxN];
int vs[mxN];
int col[mxN];
int p[mxN];

void dfs(int u, int cf = -1) {
    p[u] = cf;
    if (cf != -1) {
        col[u] = 1 - col[cf];
    }
    for (int v : adj[u]) if (v != cf) dfs(v, u);
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int& u = us[i];
        int& v = vs[i];
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    for (int i = 0; i < n - 1; ++i) {
        int u = us[i];
        int v = vs[i];

        if (col[u])cout << 1 << endl;
        else cout << 0 << endl;
    }
}
