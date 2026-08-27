#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mxN = 1e15+5;

ll solve(ll n) {
    if (n < 3) return n;
    ll a = 3;
    ll b = 2;

    for (;;) {
        ll c = a + b;
        if (c > n) break;
        b = a;
        a = c;
    }

    if (a == n) return a;
    return solve(n - a);
}

int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
