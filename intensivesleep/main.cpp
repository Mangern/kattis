#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ii> cls;
    cls.push_back({0,0});
    for (int i = 0; i < c; ++i) {
        ll a, b;
        cin >> a >> b;
        cls.push_back({a,b});
    }
    cls.push_back({n,n});

    ll ans = 0;
    for (int i = k + 1; i < (int)cls.size(); ++i) {
        auto [_1, pb] = cls[i-(k+1)];
        auto [na, _2] = cls[i];
        ans = max(ans, na - pb);
    }
    cout << ans << endl;
}
