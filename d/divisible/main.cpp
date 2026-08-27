#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;

    while (t --> 0) {
        ll d, n;
        cin >> d >> n;

        map<ll, ll> cnt;

        ll ans = 0;

        ll sm = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            ll a;
            cin >> a;

            sm += a;
            sm %= d;

            ans += cnt[sm];

            ++cnt[sm];
        }
        cout << ans << endl;
    }
}
