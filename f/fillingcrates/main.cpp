#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 1005;

ii can[mxN];

int main() {
    for (ll x = 2; x < mxN; ++x) {
        for (ll y = 2; y * x < mxN; ++y) {
            if (can[x*y] == ii{0,0}) {
                can[x*y] = {x, y};
            }
        }
    }

    ll n;
    cin >> n;

    if (can[n] != ii{0,0}) {
        cout << can[n][0] << "x" << can[n][1] << endl;
        return 0;
    }

    for (ll z = 4; n-z >= 0; ++z) {
        if (can[z] != ii{0,0} && can[n-z] != ii{0,0}) {
            cout << can[z][0] << "x" << can[z][1] << " " << can[n-z][0] << "x" << can[n-z][1] << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
}
