#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        ll n;
        cin >> n;

        ll a = -1;
        ll k = -1;
        for (ll i = 2; i * i <= 2*n; ++i) {
            if ((2 * n) % i != 0) continue;

            k = i;

            if ((2 * n / k - (k - 1)) % 2 == 0 && (2 * n / k - (k - 1)) >= 2) {
                a = (2 * n / k - (k - 1)) / 2;
                break;
            }
            k = 2 * n / i;
            if ((2 * n / k - (k - 1)) % 2 == 0 && (2 * n / k - (k - 1)) >= 2) {
                a = (2 * n / k - (k - 1)) / 2;
                break;
            }
            k = -1;
        }

        if (a == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << n << " = " << a;
            for (int i = 1; i <= k - 1; ++i) {
                cout << " + " << a+i;
            }
            cout << endl;
        }
    }
}
