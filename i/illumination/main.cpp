#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define sz(v) (int)(v).size()
#define rep(i,s,t) for (int i = (s); i < (t); ++i)

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int main() {
    int n, r, k;

    cin >> n >> r >> k;

    vector<pair<int,int>> lamps(k);

    for (auto &[i, j] : lamps) {
        cin >> i >> j;
    }
    TwoSat sat(k);

    // var i: true -> horizontal, false -> vertical
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) if (i != j) {
            auto [ri, ci] = lamps[i];
            auto [rj, cj] = lamps[j];

            if (ri == rj && abs(ci-cj) <= r) {
                // One of them must be vertical
                sat.either(~i, ~j);
            }
            if (ci == cj && abs(ri-rj) <= r) {
                sat.either(i, j);
            }
        }
    }

    cout << sat.solve() << endl;
}
