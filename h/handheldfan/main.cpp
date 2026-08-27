#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, w;
    cin >> n >> w;

    vector<ll> t(n);
    for (auto & x : t) cin >> x;

    w *= 60;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll sm = 0;
        int j;
        for (j = i; j < n; ++j) {
            sm += t[j]*2;
            if (sm>w)break;
        }
        ans=max(ans,(ll)j-i);
    }
    cout << ans << endl;
}
