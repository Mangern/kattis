#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e9;

ll book_price[105][16];
ll price[16];
ll n, m;

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        cin >> price[i];

        for (int j = 0; j < k; ++j) {
            ll idx, v;
            cin >> idx >> v;
            book_price[idx][i] = v;
        }
    }

    ll ans = INF;
    for (ll mask = 0; mask < (1<<m); ++mask) {
        ll sprice = 0;
        bool ok=1;
        for (ll i = 1; i <= n; ++i) {
            ll mprice = INF;
            for (int j = 0; j < m; ++j) if ((mask >> j) & 1) {
                if (book_price[i][j] != 0) {
                    mprice = min(mprice, book_price[i][j]);
                }
            }
            if (mprice == INF) {
                ok=0;
                break;
            }
            sprice += mprice;
        }
        for (int j = 0; j < m; ++j) if ((mask >> j) & 1) {
            sprice += price[j];
        }
        if (ok)ans=min(ans, sprice);
    }
    cout << ans << endl;
}
