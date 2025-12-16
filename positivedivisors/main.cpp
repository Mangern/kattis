#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n;
    vector<ll> rem;
    cin >> n;

    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cout << i << "\n";
            if (i * i < n)rem.push_back(n/i);
        }
    }
    while(rem.size()) {
        cout << rem.back() << "\n";
        rem.pop_back();
    }
}
