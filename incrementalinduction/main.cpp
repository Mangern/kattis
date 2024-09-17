#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int mxN = 5005;

int n;
vi adj[mxN];
int out[mxN];
int vis[mxN];

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j <= i; ++j) {
            if (s[j] == '0') {
                adj[j].push_back(i+1);
                ++out[j];
            } else {
                ++out[i+1];
                adj[i+1].push_back(j);
            }
        }
    }

    vi topo(n, 0);
    iota(begin(topo), end(topo), 0);

    sort(begin(topo), end(topo), [&] (int i, int j) {
        return adj[i].size() < adj[j].size();
    });

    vi topoid(n, 0);
    for (int i = 0; i < n; ++i) {
        topoid[topo[i]] = i;
    }

    int ans = 0;
    int sz = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; ++i) {
        ans = max(ans, sz);
        sz -= vis[i];
        for (int v : adj[topo[i]]) {
            if (topoid[v] > i) {
                ++sz;
                ++vis[topoid[v]];
            }
        }
    }

    cout << ans << endl;
}
