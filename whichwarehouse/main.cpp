//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using arr = array<ll, 2>;
using arrr = array<ll, 3>;
using vi = vector<int>;

const int mxN = 105;
const ll INF = 1e9;

ll n, m;
ll num[mxN][mxN];
ll dist[mxN][mxN];

ll hungarian(const vector<vi> &a) {
    if (a.empty()) return 0;
    int n = a.size() + 1;
    int m = a[0].size() + 1;
    vi u(n), v(m), p(m);

    for (int i = 1; i < n; ++i) {
        p[0] = i;
        int j0 = 0;
        vi dist(m, INT_MAX), pre(m, -1);
        vector<bool> done(m + 1);
        do {
            done[j0] = true;
            int i0 = p[j0], j1, delta = INT_MAX;
            for (int j = 1; j < m; ++j) if (!done[j]) {
                auto cur = a[i0 - 1][j-1] - u[i0] - v[j];
                if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
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

    return -v[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> num[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
            if (dist[i][j] == -1)dist[i][j] = INF;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    vector<vi> cost(m, vi(n, 0)); // cost[i][j] = cost of placing item i at j
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // place item i at node j
            
            for (int k = 0; k < n; ++k) {
                cost[i][j] += dist[k][j] * num[k][i];
            }
        }
    }

    cout << hungarian(cost) << endl;
}
