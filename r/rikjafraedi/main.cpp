#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using vec = array<ll, 3>;

vec operator+(const vec& a, const vec& b) {
    return {a[0]+b[0],a[1]+b[1],a[2]+b[2]};
}
const int mxN = 1e5+5;

int n, m;
bool vis[mxN];
vec point[mxN];
vector<pair<int, vec>> adj[mxN];

bool dfs(int u) {
    vis[u] = 1;
    for (auto [v, delta] : adj[u]) {
        vec nxt = point[u] + delta;
        if (vis[v]) {
            if (point[v] != nxt) {
                return false;
            }
        } else {
            point[v] = nxt;
            if (!dfs(v)) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, x, y, z;
        cin >> u >> v >> x >> y >> z, --u, --v;
        adj[u].push_back({v, {x,y,z}});
        adj[v].push_back({u, {-x,-y,-z}});
    }

    for (int u = 0; u < n; ++u) if (!vis[u]) {
        if (!dfs(u)) {
            cout << "Neibb" << endl;
            return 0;
        }
    }
    cout << "Jebb" << endl;
}
