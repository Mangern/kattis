#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) begin(v), end(v)

constexpr double pi = acos(-1.0);

constexpr double INF = numeric_limits<double>::infinity();

const int mxN = 1e4+4;

int n, m;
pair<ll, ll> points[mxN];
pair<int, int> edges[mxN];
vector<int> adj[mxN];
vector<int> deg4;

vector<int> d4_adj[mxN];
// u->v: which index in v?
vector<int> d4_adj_edge[mxN];
int vis[mxN];

// which of my edges go in?
const vector<array<int, 2>> in_configs = {
    {0, 1},
    {0, 2},
    {0, 3},
    {1, 2},
    {1, 3},
    {2, 3}
};

// idx[u, c] = 6 * u + c
// which configs are compatible?
vector<int> config_adj[6 * mxN];
// turn cost for this config
double config_cost[6 * mxN];

double turn_angle(int u1, int u2, int u3) {
    auto [x1, y1] = points[u1];
    auto [x2, y2] = points[u2];
    auto [x3, y3] = points[u3];

    double h1 = atan2(y2 - y1, x2 - x1);
    double h2 = atan2(y3 - y2, x3 - x2);

    if ((x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2) >= 0) {
        // left turn
        while (h2 < h1)
            h2 += 2 * pi;
        return h2 - h1;
    } else {
        // right turn
        while (h1 < h2)
            h1 += 2 * pi;
        return h1 - h2;
    }
}

int get_nei(int u, int idx) {
    auto [eu, ev] = edges[adj[u][idx]];
    return u ^ eu ^ ev;
}

pair<int, int> find_d4_nei(int u, int idx) {
    if (d4_adj[u][idx] != -1) 
        return {d4_adj[u][idx], d4_adj_edge[u][idx]};

    int v = get_nei(u, idx);

    if (adj[v].size() == 4) {
        d4_adj[u][idx] = v;
        for (int i = 0; i < 4; ++i) {
            if (get_nei(v, i) == u) {
                d4_adj_edge[u][idx] = i;
            }
        }
        return {v, d4_adj_edge[u][idx]};
    }

    int idx_v;
    for (idx_v = 0; idx_v < 2; ++idx_v) {
        if (get_nei(v, idx_v) != u) {
            break;
        }
    }
    auto [nei, rev_idx] = find_d4_nei(v, idx_v);
    d4_adj[u][idx] = nei;
    d4_adj_edge[u][idx] = rev_idx;
    return {nei, rev_idx};
}

double compute_config_cost(int u, int c) {
    array<int, 2> in = in_configs[c];
    array<int, 2> out;

    {
        int ptr = 0;
        for (int i = 0; i < 4; ++i) {
            if (in[0] == i) continue;
            if (in[1] == i) continue;
            out[ptr++] = i;
        }
    }

    double ret = INF;
    for (int i1 : in) {
        for (int o1 : out) {
            int i2 = in[0] ^ in[1] ^ i1;
            int o2 = out[0] ^ out[1] ^ o1;

            int vi1 = get_nei(u, i1);
            int vo1 = get_nei(u, o1);
            int vi2 = get_nei(u, i2);
            int vo2 = get_nei(u, o2);

            ret = min(ret,
                turn_angle(vi1, u, vo1) + turn_angle(vi2, u, vo2));
        }
    }
    return ret;
}

bool is_compatible(int u, int cu, int v, int cv) {
    if (u == v) return cu == cv;
    for (int iu = 0; iu < 4; ++iu) {
        if (d4_adj[u][iu] != v) continue;

        bool out_from_u = in_configs[cu][0] != iu && in_configs[cu][1] != iu;

        int iv = d4_adj_edge[u][iu];
        bool out_from_v = in_configs[cv][0] != iv && in_configs[cv][1] != iv;

        if (out_from_u && out_from_v) return false;
        if (!out_from_u && !out_from_v) return false;
    }

    return true;
}

int chosen_config[mxN];

double extra = INF;

void search(int u, int c, int depth = 0, double cur = 0.0) {
    chosen_config[u] = c;

    int here = 6 * u + c;
    cur += config_cost[here];

    // is it consistent:
    //     for each explored neighbor, the chosen configs must be compatible
    for (int v : d4_adj[u]) {
        int cv = chosen_config[v];
        if (cv == -1) continue;

        if (find(all(config_adj[here]), 6 * v + cv) == end(config_adj[here])) {
            // invalid
            chosen_config[u] = -1;
            return;
        }
    }
    if (depth + 1 == deg4.size()) {
        extra = min(extra, cur);
        return;
    }

    for (int vc : config_adj[6 * u + c]) {
        int v = vc / 6;
        int cv = vc % 6;
        if (chosen_config[v] != -1) continue;
        search(v, cv, depth + 1, cur);
    }

    chosen_config[u] = -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    double ans = 0.0;
    for (int u = 0; u < n; ++u) {
        d4_adj[u].assign(adj[u].size(), -1);
        d4_adj_edge[u].assign(adj[u].size(), -1);
        if (adj[u].size() == 2) {
            int v1 = get_nei(u, 0);
            int v2 = get_nei(u, 1);
            if (v1 == v2) {
                ans += pi;
            } else {
                ans += turn_angle(v1, u, v2);
            }
        } else {
            assert(adj[u].size() == 4);
            deg4.push_back(u);
        }
    }
    for (int u : deg4) {
        for (int i = 0; i < 4; ++i) {
            find_d4_nei(u, i);
        }
    }
    for (int u : deg4) {
        for (int c = 0; c < 6; ++c) {
            config_cost[6 * u + c] = compute_config_cost(u, c);
            for (int v : d4_adj[u]) {
                for (int cv = 0; cv < 6; ++cv) {
                    if (
                        find(all(config_adj[6 * u + c]), 6 * v + c) 
                        != end(config_adj[6 * u + c])
                    ) continue;

                    if (is_compatible(u, c, v, cv)) {
                        config_adj[6 * u + c].push_back(6 * v + c);
                    }
                }
            }
        }
    }
    if (deg4.size()) {
        int u = deg4[0];
        memset(chosen_config, -1, sizeof chosen_config);
        for (int c = 0; c < 6; ++c) {
            search(u, c);
        }
        ans += extra;
    }
    cout << setprecision(12) << fixed << ans << endl;
}
