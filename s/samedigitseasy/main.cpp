#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isdps(ll x, ll y) {
    vector<ll> cnt1(10,0),cnt2(10,0);

    {
        ll a=x,b=y;
        while (a>0) {
            ++cnt1[a%10];
            a/=10;
        }
        while (b>0) {
            ++cnt1[b%10];
            b/=10;
        }
    }
    ll c = x*y;
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

    for (ll x = a; x <= b; ++x) {
        for (ll y = x; y <= b; ++y) {
            if (isdps(x,y))ans.push_back({x, y});
        }
    }

    cout << ans.size() << " digit-preserving pair(s)" << endl;
    for (auto [x, y] : ans)cout << "x = " << x << ", y = " << y << ", xy = " << x * y << endl;
}
