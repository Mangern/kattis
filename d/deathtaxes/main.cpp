#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll shares = 0;
    double avg = 0.0;
    for (;;) {
        string cmd;
        cin >> cmd;

        if (cmd == "buy") {
            ll n, k;
            cin >> n >> k;
            avg = (shares * avg + n * k) / (double)(shares + n);
            shares += n;
        } else if (cmd == "sell") {
            ll n, k;
            cin >> n >> k;
            shares -= n;
        } else if (cmd == "split") {
            ll x;
            cin >> x;
            shares *= x;
            avg /= x;
        } else if (cmd == "merge") {
            ll x;
            cin >> x;

            shares /= x;
            avg *= x;
        } else {
            ll y;
            cin >> y;
            double gain = y * shares;
            double value = shares * avg;

            double ans;
            if (gain < value) {
                ans = gain;
            } else {
                ans = gain - (gain - value) * 0.3;
            }
            cout << setprecision(8) << fixed << ans << endl;

            break;
        }
    }
}
