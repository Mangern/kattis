#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, s;
    cin >> n >> s;

    double x = 1.0;

    for (ll i = 1; i <= n; ++i) {
        x += log10(i);
    }

    ll tot = x;

    ll tz = 0;

    ll mul = 5;

    while (mul <= n) {
        tz += n / mul;
        mul *= 5;
    }

    if (tot <= tot - tz + s) {
        cout << tot << endl;
    } else {
        cout << tot - tz + s << " " << tz << endl;
    }
}
