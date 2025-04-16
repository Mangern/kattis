#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const int mxN = 1e4+10;

int n;
vector<int> adj[mxN];
ll sz[mxN];

ll ans[2];

void dfs_sz(int u, int cf = -1) {
    sz[u] = 1;
    for (int v : adj[u]) if (v != cf) {
        dfs_sz(v,u);
        sz[u] += sz[v];
    }
}

ii calc(const vector<ll> &groups) {
    ll sm = accumulate(begin(groups), end(groups), 0);

    ll ret = 0;
    for (ll g : groups) {
        ret += g * (sm - g);
    }
    return {ret, sm};
}

void dfs(int u, int cf = -1, ll above = 0) {
    vector<ll> gr(1, above);
    for (int v : adj[u]) if (v != cf) {
        gr.push_back(sz[v]);
    }

    auto [cur, tot] = calc(gr);

    for (int v : adj[u]) if (v != cf) {
        dfs(v, u, tot - sz[v] + 1);
    }

    if (gr.size() >= 2) {
        sort(begin(gr), end(gr));

        ll x = gr.back();
        gr.pop_back();
        gr.back() += x;

        auto [alt, t] = calc(gr);

        if (cur > ans[0]) {
            ans[0] = cur;
            ans[1] = alt;
        }
    }
}

int main() {
    cin >> n;
    ++n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_sz(0);
    dfs(0);

    ans[0] /= 2;
    ans[1] /= 2;

    cout << ans[0] << " " << ans[1] << endl;
}
