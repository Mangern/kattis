#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

const int mxN = 1000;
const ll INF = 1e15;

int n, m, k;
ll dist[mxN][mxN];
ll s[mxN];
ll u[mxN];
ll t[mxN];

void compute_dist() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

bool possible(ll wait) {
    vll ld(k+1, -1);
    ld[k] = INF;

    for (int i = k - 1; i >= 0; --i) {
        ll travel = 0;
        int p = 0;
        ll mx = 0;

        ll minl = INF;

        for (int j = 1; i + j <= k; ++j) {
            travel += dist[p][u[i+j-1]];

            minl = min(minl, s[i+j-1] + wait - travel);
            if (minl < t[i+j-1])break;

            if (t[i+j-1] <= ld[i+j] - travel - dist[u[i+j-1]][0])
                ld[i] = max(ld[i], min(minl, ld[i+j] - travel - dist[u[i+j-1]][0]));

            p = u[i+j-1];
        }
        if (ld[i] < 0)return false;
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j)dist[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        ll u, v, d;
        cin >> u >> v >> d, --u, --v;
        dist[u][v] = dist[v][u] = d;
    }

    compute_dist();

    cin >> k;

    for (int i = 0; i < k; ++i) {
        cin >> s[i] >> u[i] >> t[i];
        --u[i];
    }

    ll lo = 0;
    ll hi = INF;

    while (lo < hi) {
        ll mid = (lo + hi) / 2;

        if (possible(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
