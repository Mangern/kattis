#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    unordered_set<ll> seen;
    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        if (seen.count(k - x)) {
            cout << x << " " << k - x << endl;
            return 0;
        }
        seen.insert(x);
    }
    cout << "Neibb" << endl;
}
