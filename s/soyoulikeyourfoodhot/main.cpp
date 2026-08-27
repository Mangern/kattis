#include <cassert>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

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
    string pts, p1s, p2s;
    cin >> pts >> p1s >> p2s;

    pts = pts.substr(0, pts.length() - 3) + pts.substr(pts.length() - 2, 2);
    p1s = p1s.substr(0, p1s.length() - 3) + p1s.substr(p1s.length() - 2, 2);
    p2s = p2s.substr(0, p2s.length() - 3) + p2s.substr(p2s.length() - 2, 2);

    ll pt = stoll(pts);
    ll p1 = stoll(p1s);
    ll p2 = stoll(p2s);

    ll x, y;
    ll g = ext_gcd(p1, p2, x, y);
    if (pt % g == 0) {
        x *= (pt / g);
        y *= (pt / g);

        assert(p1 * x + p2 * y == pt);
        ll a = p2 / g;
        ll b = p1 / g;

        while (x > 0) {
            x -= a;
            y += b;
        }

        while (x < 0) {
            x += a;
            y -= b;
        }
        assert(p1 * x + p2 * y == pt);

        while (x >= 0 && y >= 0) {
            cout << x << " " << y << endl;
            x += a;
            y -= b;
        }
    } else {
        cout << "none" << endl;
    }
}
