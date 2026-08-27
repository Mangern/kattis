#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isdps(ll a, ll b, ll c) {
    vector<ll> cnt1(10,0),cnt2(10,0);

    while (a>0) {
        ++cnt1[a%10];
        a/=10;
    }
    while (b>0) {
        ++cnt1[b%10];
        b/=10;
    }
    while (c>0) {
        ++cnt2[c%10];
        c/=10;
    }
    return cnt1==cnt2;
}

int main() {
    ll a,b;
    cin >> a >> b;

    vector<pair<ll,ll>> ans;

    for (ll xy = a; xy <= b; ++xy) {
        for (ll x = a; x * x <= xy; ++x) {
            if (xy % x == 0) {
                ll y = xy / x;
                assert(y>=x);
                if (isdps(x,y,xy))ans.push_back({x,y});
            }
        }
    }

    sort(begin(ans), end(ans));

    cout << ans.size() << " digit-preserving pair(s)" << endl;
    for (auto [x, y] : ans)cout << "x = " << x << ", y = " << y << ", xy = " << x * y << endl;
}
