#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll d, r, t;
    cin >> d >> r >> t;

    ll a = 2*r + 2*t + 18 - d*d - d;

    for (ll y = 1; y * y <= a; ++y) if (a % y == 0) {
        ll z = 2 * y + 2 * d + 2;
        if (z == a / y) {
            ll x = d+y;
            cout << r - ((x*(x+1)/2)-6) << endl;
            return 0;
        }
    }

    return 0;
}
