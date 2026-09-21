#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

bool above(const vi& a, const vi& b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < b[i]) return false;
    }
    return true;
}


int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<vi, vi>> algs;

    algs.emplace_back(vi(k,0),vi(k,0));

    for (int i = 0; i < n; ++i) {
        vi lb(k), ub(k);
        for (auto &x : lb) cin >> x;
        for (auto &x : ub) cin >> x;
        algs.emplace_back(lb, ub);
    }

    vector<vi> adj(n+1);
    for (int i = 0; i <= n; ++i) {
        const auto& [ilb, iub] = algs[i];
        for (int j = 0; j <= n; ++j) if (i != j) {
            const auto& [jlb, jub] = algs[j];
            if (above(iub, jlb)) {
                adj[i].push_back(j);
            }
        }
    }
    vector<bool> vis(n+1,0);
    queue<int> q;
    vis[0] = 1;
    q.push(0);
    int ans = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                ++ans;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    cout << ans << endl;
}
