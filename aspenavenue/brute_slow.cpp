#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using ld = long double;

pair<ld, vi> hungarian(const vector<vector<ld>> &a) {
    if (a.empty())return {0, {}};
    int n = a.size() + 1, m = a[0].size() + 1;
    vi p(m), ans(n-1);
    vector<ld> u(n), v(m);
    for (int i = 1; i < n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<ld> dist(m, INT_MAX), pre(m, -1);
        vector<bool> done(m+1);
        do {
            done[j0] = true;
            int i0 = p[j0], j1;
            ld delta = INFINITY;
            for (int j = 1; j < m; ++j) if (!done[j]) {
                auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < dist[j])dist[j] = cur, pre[j] = j0;
                if (dist[j] < delta)delta = dist[j], j1 = j;
            }
            for (int j = 0; j < m; ++j) {
                if (done[j])u[p[j]] += delta, v[j] -= delta;
                else dist[j] -= delta;
            }
            j0 = j1;
        } while (p[j0]);
        while (j0) {
            int j1 = pre[j0];
            p[j0] = p[j1], j0 = j1;
        }
    }
    for (int j = 1; j < m; ++j) if (p[j])ans[p[j] - 1] = j - 1;
    return {-v[0], ans};
}

ll n, l, w;

int main() {
    cin >> n >> l >> w;

    vi p(n);

    for (auto& x : p)cin >> x;

    vector<pair<ld,ld>> positions;

    for (int i = 0; i < (n >> 1); ++i) {
        positions.push_back({0, (ld)i * l / ((ld)(n/2 - 1))});
        positions.push_back({w, (ld)i * l / ((ld)(n / 2 - 1))});
    }

    vector<vector<ld>> cost(n, vector<ld>(n, INFINITY));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            auto [x, y] = positions[j];
            ld px = 0;
            ld py = p[i];
            cost[i][j] = sqrtl((px - x) * (px - x) + (py - y) * (py - y));
            //cout << cost[i][j] << " ";
        }
        //cout << endl;
    }

    auto [mincost, match] = hungarian(cost);

    cout << setprecision(8) << fixed << mincost << endl;

    return 0;
}
