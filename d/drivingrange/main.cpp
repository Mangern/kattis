#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e6+6;

int p[mxN];
int rnk[mxN];
int nset = 0;

int find(int i) {
    return p[i] == i ? i : (p[i] = find(p[i]));
}

bool join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) return false;

    --nset;
    if (rnk[i] > rnk[j]) {
        p[j] = i;
    } else {
        p[i] = j;
        if (rnk[i] == rnk[j])++rnk[j];
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    nset = n;
    vector<array<ll, 3>> ed(m);
    for (auto &[w, u, v] : ed) {
        cin >> u >> v >> w;
    }
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    sort(begin(ed), end(ed));

    ll ans = -1;
    for (auto [w, u, v] : ed) {
        if (join(u, v)) {
            ans = w;
        }
    }

    if (nset != 1)ans = -1;
    if (ans == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else cout << ans << endl;
}
