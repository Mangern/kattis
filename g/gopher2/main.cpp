#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define sz(v) (int)(v).size()
#define rep(i,s,n) for (int i = (s); i < (n); ++i)

int hopcroftKarp(vector<vi>& g, vi& r) {
	int n = sz(g), res = 0;
	vi l(n, -1), q(n), d(n);
	auto dfs = [&](auto f, int u) -> bool {
		int t = exchange(d[u], 0) + 1;
		for (int v : g[u])
			if (r[v] == -1 || (d[r[v]] == t && f(f, r[v])))
				return l[u] = v, r[v] = u, 1;
		return 0;
	};
	for (int t = 0, f = 0;; t = f = 0, d.assign(n, 0)) {
		rep(i,0,n) if (l[i] == -1) q[t++] = i, d[i] = 1;
		rep(i,0,t) for (int v : g[q[i]]) {
			if (r[v] == -1) f = 1;
			else if (!d[r[v]]) d[r[v]] = d[q[i]] + 1, q[t++] = r[v];
		}
		if (!f) return res;
		rep(i,0,n) if (l[i] == -1) res += dfs(dfs, i);
	}
}

int main() {
    for (;;) {
        int n, m, s, v;
        if (!(cin >> n)) break;
        cin >> m >> s >> v;
        vector<pair<double,double>> loc_lft, loc_rgt;

        for (int i = 0; i < n; ++i) {
            double x, y; 
            cin >> x >> y;
            loc_lft.emplace_back(x, y);
        }
        for (int i = 0; i < m; ++i) {
            double x, y; 
            cin >> x >> y;
            loc_rgt.emplace_back(x, y);
        }

        vector<vi> adj(n);
        vi r(m,-1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                double dx = loc_lft[i].first - loc_rgt[j].first;
                double dy = loc_lft[i].second - loc_rgt[j].second;

                if (dx * dx + dy * dy <= (double)s * s * (double)v * v + 1e-9) {
                    adj[i].push_back(j);
                }
            }
        }
        int M = hopcroftKarp(adj, r);
        cout << n - M << endl;
    }
}
