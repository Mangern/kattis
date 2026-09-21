#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    if (k * k < n) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> a;

    int ans = 0;
    for (ll i = 0; i < n; i += k) {
        int ptr = min(n, i + k);
        for (int j = 0; j < k; ++j) {
            if (ans < n) {
                cout << ptr-- << ' ';
                ++ans;
            }
        }
    }
    cout << endl;
}
