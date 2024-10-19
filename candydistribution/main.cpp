#include <iostream>
using namespace std;
using ll = long long;

// a * x + b * y == gcd(a, b)
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll xx, yy;
    ll g = ext_gcd(b, a%b, xx, yy);
    x = yy;
    y = xx - (a / b) * yy;
    return g;
}

int main() {
    int t;
    cin >> t;
    while (t-->0) {
        ll n, x;
        ll k, c;
        cin >> k >> c;

        if (c == 1) {
            if (k == 1000000000) {
                cout << "IMPOSSIBLE" << endl;
            } else cout << k+1 << endl;
            continue;
        }

        if (k == 1) {
            cout << 1 << endl;
            continue;
        }

        ll g = ext_gcd(c, k, n, x);
        n = ((n % k) + k) % k;
        if ((c * n) % k != 1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << n << endl;
        }
    }
}
