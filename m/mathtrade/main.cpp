#include <bits/stdc++.h>
using namespace std;

const int mxN = 105;

int n;
string have[mxN];
string want[mxN];
int nxt[mxN];

int vis[mxN];
int dist[mxN];

int dfs(int u) {
    vis[u] = 1;

    if (!nxt[u]) return 0;

    if (vis[nxt[u]] == 2) {
        return 0;
    }
    int ret;
    if (vis[nxt[u]] == 1) {
        ret = dist[u] + 1 - dist[nxt[u]];
    } else {
        dist[nxt[u]] = dist[u] + 1;
        ret = dfs(nxt[u]);
    }
    vis[u] = 2;
    return ret;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> have[i] >> have[i] >> want[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (have[j] == want[i]) {
                nxt[i] = j;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ans = max(ans, dfs(i));
        }
    }

    if (!ans)cout << "No trades possible" << endl;
    else {
        cout << ans << endl;
    }
}
