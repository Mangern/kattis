#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const ll INF = numeric_limits<ll>::max() / 8;

const int mxN = 5e5+5;
const int mxK = 20;
ll n,k;

vector<ii> adj[mxN];
int p[mxN][mxK];
int depth[mxN];
int mrk[mxN];
ll dist[mxN];
ll md1[mxN], md2[mxN];
ll far[mxN];
int nxt1[mxN];
int par[mxN];

void dfs(int u, int cf = -1) {
    for (auto [v, w] : adj[u]) if (v != cf) {
        depth[v] = depth[u] + 1;
        p[0][v] = u;
        dfs(v, u);
    }
}

void dfsmrk(int u, int cf = -1) {
    for (auto [v, w] : adj[u]) if (v != cf) {
        dfsmrk(v, u);

        if (mrk[v]) {
            mrk[u] = 1;
        }
    }
}

void dfs1(int u, int cf = -1) {
    for (auto [v, w] : adj[u]) if (mrk[v] && v != cf) {
        dfs1(v, u);
        ll cmp = md1[v] + w;
        if (cmp > md1[u]) {
            md2[u] = md1[u];
            md1[u] = cmp;
            nxt1[u] = v;
        } else if (cmp > md2[u]) {
            md2[u] = cmp;
        }
    }
}

void dfs2(int u, ll cur = 0, int cf = -1) {
    far[u] = max(cur, md1[u]);

    for (auto [v, w] : adj[u]) if (mrk[v] && v != cf) {
        if (v != nxt1[u]) dfs2(v, w + max(cur, md1[u]), u);
        else              dfs2(v, w + max(cur, md2[u]), u);
    }
}

int main() {
    scanf("%lld%lld", &n, &k);

    for (int i = 0; i < n - 1; ++i) {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(0);

    vector<ll> a(k);
    for (auto &u : a) {
        scanf("%lld", &u);
        --u;
        mrk[u] = 1;
    }

    dfsmrk(a[0]);

    ll rem = 0;

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!mrk[i]) {
            dist[i] = INF;
            continue;
        }
        q.push(i);
        par[i] = i;
        for (auto [j, w] : adj[i]) {
            if (!mrk[j]) continue;
            rem += w;
        }
    }

    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = par[u];
                q.push(v);
            }
        }
    }

    dfs1(a[0]);
    dfs2(a[0]);

    for (int i = 0; i < n; ++i) {
        int p = par[i];
        ll ans = rem - far[p] + dist[i];
        printf("%lld\n", ans);
    }
}
