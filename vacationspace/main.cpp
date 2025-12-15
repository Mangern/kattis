#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    ll n;
    cin >> n;

    vector<ii> pos(n);
    for (int i=  0; i < n; ++i) {
        cin >> pos[i][0];
        pos[i][1] = i;
    }
    sort(begin(pos), end(pos));

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    ll ans = pos[0][1];
    ll ansd = pos[1][0] - pos[0][0];

    for (int i = 1; i < n; ++i) {
        ll d = pos[i][0] - pos[i-1][0];
        if (i < n - 1) d = min(d, pos[i+1][0] - pos[i][0]);

        if (d > ansd || d == ansd && pos[i][1]<ans) {
            ans = pos[i][1];
            ansd = d;
        }
    }

    cout << ans+1 << endl;
}
