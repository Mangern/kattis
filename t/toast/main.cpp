#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ll n,t;
    ld d;
    cin >> n >> d >> t;

    ll pp = 2 * t / n;

    if (pp == n - 1) {
        cout << 0 << " " << d << endl;
        return 0;
    }

    ll np = pp / 2;

    ld alpha = np * 2 * M_PI / (ld)n;
    ld beta  = (np+1)*2*M_PI /(ld)n;

    ld rmin = d / sin(beta/2);
    ld rmax = d / sin(alpha/2);

    cout << setprecision(5) << fixed << rmin << " " << setprecision(5) << fixed << rmax << endl;
}
