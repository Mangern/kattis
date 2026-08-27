#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 1005;

int n;
ll x[mxN], y[mxN], rad[mxN];
vector<int> adj[mxN];

ii rat[mxN];

ii combine(ii a, ii b) {
    ll p = a[0] * b[0];
    ll q = a[1] * b[1];

    if (p < 0) {
        p *= -1;
        q *= -1;
    }

    ll g = gcd(abs(p), abs(q));
    p /= g;
    q /= g;
    return {p,q};
}

void dfs(int u, int cf = -1, ii r = {1, 1}) {
    if (rat[u][0] != -1) {
        if (rat[u] != r) {
            cout << -1 << endl;
            exit(0);
        }
        return;
    }
    rat[u] = r;
    for (int v : adj[u]) {
        dfs(v, u, combine(r, ii{rad[v], -rad[u]}));
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> rad[i];
        rat[i] = {-1,-1};
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j) {
            if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) == (rad[i] + rad[j]) * (rad[i] + rad[j])) {
                adj[i].push_back(j);
            }
        }
    }

    dfs(0);

    if (rat[n-1][0] == -1) {
        cout << 0 << endl;
        return 0;
    }

    cout << rat[n-1][0] << " " << rat[n-1][1] << endl;
}
