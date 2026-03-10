#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<ll> groups[4];
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        groups[x % 4].push_back(x);
    }
    for (int i = 0; i < 4; ++i) {
        sort(begin(groups[i]), end(groups[i]));
    }

    while (groups[k%4].size()) {
        ll s = groups[k%4].back();
        groups[k%4].pop_back();
        k += s;
    }
    cout << k << endl;
}
