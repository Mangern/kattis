#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e8+2;

int main() {
    ll p;
    cin >> p;

    // 1,5,10,25
    ll num[4];
    cin >> num[0] >> num[1] >> num[2] >> num[3];


    ll best = -1;
    num[0] = min(num[0], p);
    num[1] = min(num[1], p/5);
    num[2] = min(num[2], p/10);
    num[3] = min(num[3], p/25);

    for (ll n0 = max(0LL, num[0] - 24); n0 <= num[0]; ++n0) {
        for (ll n1 = max(0LL, num[1] - 24); n1 <= num[1]; ++n1) {
            for (ll n2 = max(0LL, num[2] - 24); n2 <= num[2]; ++n2) {
                ll sm = n0 + n1 * 5 + n2 * 10;
                if (sm > p) continue;

                if ((p - sm) % 25 == 0 && (p-sm)/25 <= num[3]) {
                    best = max(best, n0 + n1 + n2 + (p-sm)/25);
                }
            }
        }
    }

    if (best == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << best << endl;
    }
}
