#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
using ii = array<ll,2>;

int main() {
    int n;
    cin >> n;

    map<ii, ll> mp;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;

        for (const auto& [dx, dy] : vector<ii>{
            {2018, 0},
            {-2018, 0},
            {0, 2018},
            {0, -2018},
            {1118, 1680},
            {-1118, 1680},
            {1118, -1680},
            {-1118, -1680},
            {1680, 1118},
            {-1680, 1118},
            {1680, -1118},
            {-1680, -1118}}) {
            ans += mp[{x+dx, y+dy}];
        }

        ++mp[{x, y}];
    }

    cout << ans << endl;
}
