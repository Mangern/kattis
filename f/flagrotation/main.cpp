#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> cnt;
    for (auto &x : a) {
        cin >> x;
        ++cnt[x];
    }

    ll ans = 0;
    for (auto x : a) {
        ans += n - cnt[x];
    }
    cout << ans << endl;
}
