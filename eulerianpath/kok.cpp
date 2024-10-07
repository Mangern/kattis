#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;

#define sz(v) v.size()

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

int main() {
    while (true) {
        int n,m;
        cin >> n >> m;
        if (!n) break;

        vector<vector<pii>> gr(n, vector<pii>());

        vi in(n, 0);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            gr[u].push_back({v, i});
            ++in[v];
        }
        int src = 0;
        for (int i = 0; i < n; ++i) if (gr[i].size() > in[i]) {
            src = i;
            break;
        }
        vi path = eulerWalk(gr, m, src);

        if (path.empty()) {
            cout << "Impossible" << endl;
        } else {
            for (auto v : path)cout << v << " ";
            cout << endl;
        }
    }
}
