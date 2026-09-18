#include <bits/stdc++.h>
using namespace std;

using ld = long double;

const ld EPS = 1e-11;
const ld INF = numeric_limits<ld>::infinity();

const int mxN = 30010;

int s, r, d;

// Optimization variable
// Goal: minimize w[1]
// Indexed by station or reservoir
ld w[mxN];

// For each station, which ducts connect out of it?
vector<int> duct_out[mxN];

// For each duct, which station is upstream?
int station_in[mxN];
vector<pair<ld, int>> station_out[mxN];

vector<int> topo;

void propagate_w() {
    for (int i = 1; i <= s; ++i) {
        w[i] = 0.0;
    }

    for (int i : topo) {
        ld s_here = 0.0;
        for (auto [p, j] : station_out[i]) {
            s_here += p * w[j];
        }
        w[station_in[i]] = max(w[station_in[i]], s_here);
    }
}

const int OFF = 10005;
bool vis[mxN];
bool reached[mxN];

bool dfs_topo(int u, bool is_duct = 0) {
    if (is_duct) {
        vis[OFF+u] = 1;
        bool ret = false;
        for (auto [_, v] : station_out[u]) {
            if (vis[v]) {
                if (reached[v])ret = true;
                continue;
            }
            if (dfs_topo(v, false)) ret = true;
        }
        if (ret) {
            topo.push_back(u);
        }
        reached[OFF+u] = ret;
        return ret;
    } else {
        vis[u] = 1;
        bool ret = u > s;
        for (auto v : duct_out[u]) {
            if (vis[OFF+v]) {
                if (reached[OFF+v])ret = true;
                continue;
            }
            if (dfs_topo(v, true)) ret = true;
        }
        reached[u] = ret;
        return ret;
    }
}

void optimize_2() {
    ld ub = 1.0 - w[s+3];
    ld lo = 0.0;
    ld hi = ub;

    while (hi - lo > EPS) {
        ld m1 = lo + (hi - lo) * 1.0 / 3.0;
        ld m2 = lo + (hi - lo) * 2.0 / 3.0;

        w[s+1] = m1;
        w[s+2] = ub - m1;
        propagate_w();

        ld score_1 = w[1];

        w[s+1] = m2;
        w[s+2] = ub - m2;
        propagate_w();

        ld score_2 = w[1];

        if (score_1 <= score_2) {
            hi = m2;
        } else {
            lo = m1;
        }
    }

    w[s+1] = lo;
    w[s+2] = ub - lo;
    propagate_w();
}

int main() {
    cin >> s >> r >> d;

    for (int i = 1; i <= d; ++i) {
        int k;
        cin >> station_in[i] >> k;

        duct_out[station_in[i]].push_back(i);

        for (int j = 0; j < k; ++j) {
            int o, p;
            cin >> o >> p;

            ld r = (ld)p / 100.0;
            station_out[i].push_back({r, o});
        }
    }

    dfs_topo(1);

    if (r == 1) {
        w[s+1] = 1.0;
        propagate_w();
    } else if (r == 2) {
        w[s+3] = 0.0;
        optimize_2();
    } else {
        ld lo = 0.0;
        ld hi = 1.0;

        while (hi - lo > EPS) {
            ld m1 = lo + (hi - lo) * 1.0 / 3.0;
            ld m2 = lo + (hi - lo) * 2.0 / 3.0;
            w[s+3] = m1;
            optimize_2();
            ld score_1 = w[1];
            w[s+3] = m2;
            optimize_2();
            ld score_2 = w[1];
            if (score_1 <= score_2) {
                hi = m2;
            } else {
                lo = m1;
            }
        }
    }

    cout << setprecision(9) << fixed << w[1]*100.0 << endl;
}
