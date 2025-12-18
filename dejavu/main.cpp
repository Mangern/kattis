#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const ll mxN = 1e5+5;

ll atx[mxN];
ll aty[mxN];

int main() {
    vector<ii> pts;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        ++atx[x];
        ++aty[y];
        pts.push_back({x,y});
    }

    ll ans = 0;
    for (auto [x, y] : pts) {
        ll cx = atx[x] - 1;
        ll cy = aty[y] - 1;
        ans += cx * cy;
    }
    cout << ans << endl;
}
