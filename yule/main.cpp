#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll n, bool sign = false) {
    if (n <= 3)return n;

    ll i = sqrtl(n);
    cout << i << endl;
    ll r = solve(i - 1, !sign);

    if (sign)n += r;
    else n -= r;
    return n;
}

int main() {
    ll n;
    cin >> n;

    cout << solve(n) << endl;
}
