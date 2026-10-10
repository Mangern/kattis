#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) begin(v), end(v)

constexpr double pi = acos(-1.0);

const int mxN = 1e4+4;

struct UnionFind {
    vector<int> p;
    vector<int> rnk;
    int num_sets = 0;

    UnionFind(int n) {
        p.assign(n, 0);
        rnk.assign(n, 0);
        iota(all(p), 0);
        num_sets = n;
    }

    int find(int i) {
        return p[i] == i ? i : p[i] = find(p[i]);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j) return false;
        --num_sets;

        if (rnk[i] > rnk[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if (rnk[i] == rnk[j])++rnk[j];
        }
        return true;
    }
};


int n, m;
pair<ll, ll> pts[mxN];
vector<int> adj[mxN];
pair<int, int> edges[2 * mxN];
vector<pair<double, int>> configs[mxN];

double turn_angle(int u1, int u2, int u3) {
    auto [x1, y1] = pts[u1];
    auto [x2, y2] = pts[u2];
    auto [x3, y3] = pts[u3];

    double h1 = atan2(y2 - y1, x2 - x1);
    double h2 = atan2(y3 - y2, x3 - x2);

    if ((x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2) >= 0) {
        double ret = h2 - h1;
        if (ret < 0)ret += 2 * pi;
        return ret;
    } else {
        double ret = h1 - h2;
        if (ret < 0)ret += 2 * pi;
        return ret;
    }
}

int get_nei(int u, int idx) {
    auto [eu, ev] = edges[adj[u][idx]];
    return u ^ eu ^ ev;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> pts[i].first >> pts[i].second;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edges[i] = {u, v};
    }

    for (int u = 0; u < n; ++u) {
        if (adj[u].size() == 4) {
            for (int j = 1; j < 4; ++j) {
                int v0 = get_nei(u, 0);
                int vj = get_nei(u, j);
                int v1 = get_nei(u, (j == 1 ? 2 : 1));
                int v2 = get_nei(u, (j == 3 ? 2 : 3));
                double score = turn_angle(v0, u, vj) + turn_angle(v1, u, v2);
                configs[u].push_back({score, j});
            }
        } else {
            int v1 = get_nei(u, 0);
            int v2 = get_nei(u, 1);
            double score = turn_angle(v1, u, v2);
            configs[u].push_back({score, 1});
        }
        sort(all(configs[u]));
    }
    vector<int> nodes(n);
    iota(all(nodes), 0);
    sort(all(nodes), [&](const int& u1, const int& u2) {
        if (adj[u1].size() != adj[u2].size())
            return adj[u1].size() < adj[u2].size();
        if (adj[u1].size() == 2) {
            return u1 < u2;
        }
        return configs[u1][1].first - configs[u1][0].first 
             > configs[u2][1].first - configs[u2][0].first;
    });

    UnionFind uf(m);

    int last = nodes.back();
    double ans = 0;
    vector<int> choice(n, -1);
    for (int u : nodes) {
        if (adj[u].size() == 2) {
            ans += configs[u][0].first;
            choice[u] = 0;
            uf.join(adj[u][0], adj[u][1]);
        } else {
            int e0 = adj[u][0];
            int idx = 0;
            for (auto [score, j] : configs[u]) {
                int ej = adj[u][j];
                int e1 = adj[u][j == 1 ? 2 : 1];
                int e2 = adj[u][j == 3 ? 2 : 3];

                if (idx == 0 && (uf.find(e0) == uf.find(ej) || uf.find(e1) == uf.find(e2))) {
                    ++idx;
                    continue;
                }
                ans += score;
                uf.join(e0, ej);
                uf.join(e1, e2);
                choice[u] = idx;
                break;
            }
        }
    }

    vector<tuple<double, int, int>> rem;
    for (int u : nodes) {
        if (adj[u].size() == 2) continue;

        auto [score, j] = configs[u][choice[u]];
        int e0 = adj[u][0];
        int e1 = adj[u][j == 1 ? 2 : 1];

        if (uf.find(e0) != uf.find(e1)) {
            double score_diff = configs[u][1 - choice[u]].first - score;
            rem.emplace_back(score_diff, e0, e1);
        }
    }
    sort(all(rem));
    for (auto [delta, i, j] : rem) {
        if (uf.find(i) != uf.find(j)) {
            ans += delta;
            uf.join(i, j);
        }
    }

    cout << setprecision(12) << fixed << ans << endl;
}
