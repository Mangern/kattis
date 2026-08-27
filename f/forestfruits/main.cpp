#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

bool solve() {
    ll n, m, c, k, nd;
    cin >> n >> m >> c >> k >> nd;

    vector<vector<ii>> adj(n, vector<ii>());

    for (int i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    vector<ll> dist(n, numeric_limits<ll>::max());

    dist[0] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d)continue;

        for (auto [w, v] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d+w;
                pq.push({dist[v],v});
            }
        }
    }

    vector<ll> cs(c);
    for (auto& x : cs)cin >> x, --x;
    sort(begin(cs), end(cs), [&] (auto a, auto b) { return dist[a] < dist[b]; });

    ll ans = 0;

    if (k > cs.size() && nd > cs.size()) {
        cout << -1 << endl;
        return false;
    }

    if (k > cs.size()) {
        cout << 2*dist[cs[nd-1]] << endl;
        return false;
    }

    if (nd > cs.size() && dist[cs[k-1]] == numeric_limits<ll>::max()) {
        cout << -1 << endl;
        return false;
    } else if (nd > cs.size()) {
        cout << 2*dist[cs[k-1]] << endl;
        return false;
    }

    if (dist[cs[min(nd,k)-1]] == numeric_limits<ll>::max()) {
        cout << -1 << endl;
        return false;
    }

    cout << 2*dist[cs[min(nd,k) - 1]] << endl;

    return false;
}

int main() {
    while (solve()){}
}
