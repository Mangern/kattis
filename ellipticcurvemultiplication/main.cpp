#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mpow(ll a, ll b, ll m) {
    if (b == 0) return 1;
    ll r = mpow(a, b >> 1, m);
    r = (r * r) % m;
    if (b & 1) r = (r * a) % m;
    return r;
}

ll inv(ll x, ll p) {
    return mpow(x, p - 2, p);
}

struct EllipticPoint {
    ll x, y, a, b, p;

    bool is_zero() const {
        return x == -1;
    }

    EllipticPoint(ll x, ll y, ll a, ll b, ll p) : a(a), b(b), p(p) {
        if (x != -1) {
            this->x = (x % p + p) % p;
            this->y = (y % p + p) % p;
        } else {
            this->x = -1;
        }
    }

    EllipticPoint add(const EllipticPoint& other, ll lambda) const {
        assert(a == other.a);
        assert(b == other.b);
        assert(p == other.p);

        if (is_zero()) return other;
        if (other.is_zero()) return *this;

        ll xr = ((lambda * lambda % p - (x + other.x) % p) % p + p) % p;
        ll yr = ((lambda * ((x - xr) % p) % p - y) % p + p) % p;
        return EllipticPoint(xr, yr, a, b, p);
    }

    EllipticPoint add(const EllipticPoint& other) const {
        if (is_zero()) return other;
        if (other.is_zero()) return *this;

        if (x == other.x) {
            // return 0
            if (y == p - other.y) return EllipticPoint(-1, -1, a, b, p);
            return this->dbl();
        }
        ll lambda = (((other.y - y) % p + p) % p * inv(((other.x - x) % p + p) % p, p)) % p;
        return this->add(other, lambda);
    }

    EllipticPoint dbl() const {
        if (is_zero()) return *this;
        if (y == 0) return EllipticPoint(-1, -1, a, b, p);
        ll lambda = (((3 * x) % p * x % p + a) % p * inv(2 * y % p, p)) % p;
        return this->add(*this, lambda);
    }
};

int main() {
    ll a, b, p, n, x, y;
    cin >> p >> a >> b >> n >> x >> y;
    EllipticPoint P(x, y, a, b, p);
    EllipticPoint res(-1, -1, a, b, p);
    for (ll i = 62; i >= 0; --i) {
        res = res.dbl();
        if ((n >> i) & 1) {
            res = res.add(P);
        }
    }

    if (res.is_zero()) {
        cout << "-1 -1" << endl;
    } else {
        cout << res.x << " " << res.y << endl;
    }
}
