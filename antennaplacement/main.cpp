#include <bits/stdc++.h>
#include <limits>
using namespace std;
using ll = long long;
using vi = vector<int>;

#define all(v) begin(v), end(v)
#define sz(v) ((int)(v).size())
#define rep(i, lo, hi) for (int i = (lo); i < (hi); ++i)

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

void testCase() {
    int n, m;
    cin >> n >> m;
    // i * m + j

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    // (i + j) % 2

    int nl = 0;
    int nr = 0;
    vi mp(n*m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                if ((i + j) % 2 == 0) {
                    mp[i*m+j] = nl++;
                } else {
                    mp[i*m+j] = nr++;
                }
            }
        }
    }

    vector<vi> adj(nl);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*' && (i+j)%2 == 0) {
                for (auto [ni, nj] : vector<pair<int,int>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (grid[ni][nj] != '*')continue;
                    adj[mp[i*m+j]].push_back(mp[ni*m+nj]);
                }
            }
        }
    }

    vi mtch(nr,-1);
    int mvc = hopcroftKarp(adj, mtch);
    cout << nl + nr - mvc << endl;
}


int main() {

    int t;
    cin >> t;
    while (t-->0)testCase();
}
