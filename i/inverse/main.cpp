#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll best_s = 1e18;
    ll ans_a = -1, ans_b = -1;
    for (ll a = n+1; a < 2 * n; ++a) {
        if (a * n % (a - n) == 0) {
            ll b = a * n / (a - n);
            if (a + b < best_s) {
                best_s = a + b;
                ans_a = a;
                ans_b = b;
            }
        }
    }
    cout << ans_a << " " << ans_b << endl;
}
