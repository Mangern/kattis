#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    for (ll a = 1; a < n; ++a) {
        for (ll b = 1; a + b < n; ++b) {
            ll c = sqrt(a*a+b*b);
            if (c * c != a * a + b * b)
                ++c;


            if (c * c == a * a + b * b && a + b + c == n) {
                cout << a << " " << b << " " << c << endl;
                return 0;
            }
        }
    }
    cout << 0 << " " << 0 << " " << 0 << endl;
}
