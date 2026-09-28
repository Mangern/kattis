#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        ll b, k;
        cin >> b >> k;

        ll ans = 1;

        for (ll d = 1; d * d <= b - 1; ++d) {
            if ((b - 1) % d == 0) {
                if (d <= k)ans = max(ans, d);
                if ((b - 1)/d <= k)ans = max(ans, (b-1)/d);
            }
        }
        cout << ans << '\n';
    }
}
