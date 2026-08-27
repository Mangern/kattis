#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ld EPS = 1e-12;

const ll MX = 2;

int main() {
    ll n, m;
    cin >> n >> m;

    ll s = max(0LL, m - n);

    ld coef = 1.0;
    ll a = 0;
    ll b = 0;
    ll rem2 = n;
    for (ll i = 1; i <= n; ++i) {
        coef *= i;
        while (rem2 > 0 && log2(coef) > MX) {
            coef /= 2.0;
            --rem2;
        }
        while (a < m - s && log2(coef) > MX) {
            ++a;
            coef /= a;
        }
        while (b < n - m + s && log2(coef) > MX) {
            ++b;
            coef /= b;
        }
    }

    deque<ll> missa;
    deque<ll> missb;

    // need to divide both ans and coeff with these values eventually
    for (ll i = a + 1; i <= m - s; ++i) {
        missa.push_back(i);
    }

    for (ll i = b + 1; i <= n - m + s; ++i) {
        missb.push_back(i);
    }

    //cout << a << " " << b << " " << rem2 << endl;
    //cout << setprecision(12) << fixed << coef << endl;

    ld ans = 0.0;
    a = m - s;
    b = n - m + s;
    for (ll i = s; i <= m; ++i) {
        ans += coef * i;
        coef *= a;
        coef /= b + 1;

        while (rem2 > 0 && log2(ans) > MX) {
            ans /= 2.0;
            coef /= 2.0;
            --rem2;
        }

        while (missa.size() && log2(ans) > MX) {
            ans /= missa.back();
            coef /= missa.back();
            missa.pop_back();
        }

        while (missb.size() && log2(ans) > MX) {
            ans /= missb.back();
            coef /= missb.back();
            missb.pop_back();
        }

        --a;
        ++b;
    }
    while (rem2>0) {
        --rem2;
        ans /= 2.0;
    }
    while (missa.size()) {
        ans /= missa.back();
        missa.pop_back();
    }
    while (missb.size()) {
        ans /= missb.back();
        missb.pop_back();
    }
    cout << setprecision(10) << fixed << ans << endl;
}
