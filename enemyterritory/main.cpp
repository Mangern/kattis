#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1005;

// dist to enemy
int n, m, k;
ll dist[mxN*mxN];
// dist s->t
ll path[mxN*mxN];
int s, t;

bool can(ll mind) {
    memset(path, -1, sizeof path);

    if (dist[s] < mind) return false;
    queue<int> q;
    q.push(s);
    path[s] = 0;

    while (q.size()) {
        int u = q.front(); q.pop();

        int i = u / m, j = u % m;
        for (auto [ni, nj] : vector<array<int,2>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            int v = ni * m + nj;
            if (dist[v] < mind) continue;
            if (path[v] != -1) continue;
            path[v] = path[u] + 1;
            q.push(v);
        }

    }

    return path[t] != -1;
}

int main() {
    cin >> k >> n >> m;

    memset(dist, -1, sizeof dist);

    int xi, yi, xr, yr;
    cin >> xi >> yi >> xr >> yr;

    s = xi * m + yi;
    t = xr * m + yr;

    queue<int> q;

    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;

        u = u * m + v;
        q.push(u);
        dist[u] = 0;
    }

    while (q.size()) {
        int u = q.front();
        q.pop();

        int i = u / m, j = u % m;
        for (auto [ni, nj] : vector<array<int,2>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            int v = ni * m + nj;
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    ll lo = 0;
    ll hi = m + n;

    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (can(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    can(lo);

    cout << lo << " " << path[t] << endl;
}
