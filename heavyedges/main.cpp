#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define all(v) begin(v), end(v)
#define sz(v) ((int)(v).size())

struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
        rnk = vi(n,0);
        sz = vi(n,1);
    }

    int find(int i) {
        if (p[i] == i)return i;
        return p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i)==find(j);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return 0;
        if (rnk[i] < rnk[j]) {
            sz[j] += sz[i];
            p[i] = j;
        } else {
            sz[i] += sz[j];
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};

int Time;
vector<int> st;
template<class F>
int dfs(int at, int par, F& f, map<int, int> &num, const map<int, vector<pair<int,int>>> &ed) {
	int me = num[at] = ++Time, top = me;
	for (auto [y, e] : ed.at(at)) if (e != par) {
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = sz(st);
			int up = dfs(y, e, f, num, ed);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
				f(vi(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me) st.push_back(e);
			else { /* e is a bridge */ }
		}
	}
	return top;
}

template<class F>
void bicomps(F f, const map<int, vector<pair<int,int>>> &ed) {
    map<int, int> num;
    Time = 0;
    st.clear();
	for(auto it = begin(ed); it != end(ed); ++it) 
        if (!num[it->first]) dfs(it->first, -1, f, num, ed);
}

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);

    vector<array<int, 3>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        edges.push_back({w, u, v});
    }

    int ans = 0;
    sort(begin(edges), end(edges));
    for (int i = 0; i < m;) {
        int j;
        for (j = i; j < m; ++j) {
            if (edges[j][0] != edges[i][0]) break;
        }
        map<int, vector<pair<int, int>>> cadj;
        int eid = 0;
        for (int k = i; k < j; ++k) {
            auto [w, u, v] = edges[k];
            u = uf.find(u);
            v = uf.find(v);

            if (u == v) {
                ++ans;
                continue;
            }
            cadj[u].push_back({v, eid});
            cadj[v].push_back({u, eid++});
        }

        bicomps([&] (auto comp_edges) {
            ans += comp_edges.size();
        }, cadj);

        for (int k = i; k < j; ++k) {
            auto [w, u, v] = edges[k];
            uf.join(u, v);
        }

        i = j;
    }
    cout << ans << endl;
}
