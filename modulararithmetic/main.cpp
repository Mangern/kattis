#include <iostream>
using namespace std;
using ll = __int128;

// a * x + b * y == gcd(a, b)
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll xx, yy;
    ll g = ext_gcd(b, a % b, xx, yy);
    x = yy;
    y = xx - (a / b) * yy;
    return g;
}


int main() {
    for (;;) {
        long long inn, t;
        cin >> inn >> t;
        if (!inn) break;

        ll n = inn;
        while (t --> 0) {
            ll a, b;
            char op;
            long long ina, inb;
            cin >> ina >> op >> inb;

            a = ina;
            b = inb;

            if (op == '+') {
                long long res = ((a + b) % n + n) % n;
                cout << res << endl;
            } else if (op == '-') {
                long long res = ((a - b) % n + n) % n;
                cout << res << endl;
            } else if (op == '*') {
                long long res = ((a * b) % n + n) % n;
                cout << res << endl;
            } else {
                ll binv, k;
                ll g = ext_gcd(b, n, binv, k);
                binv = (binv % n + n) % n;
                if ((b * binv) % n != 1) {
                    cout << -1 << endl;
                    continue;
                }
                long long res = ((a * binv % n) + n) % n;
                cout << res << endl;
            }
        }
    }
}
