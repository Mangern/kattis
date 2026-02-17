#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll s) {
    if (s == 1) return 1;

    for (ll x = 2; x * x <= s; ++x) {
        if (s % x == 0) return 1 + solve(s / x);
    }
    return 2;
}

int main() {
    ll s;
    cin >> s;
    cout << solve(s) << endl;
}
