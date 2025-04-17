#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mxN = 200010;

ll n, q;
constexpr ll sqrt_n = 448;
ll a[mxN];
ll b[sqrt_n][sqrt_n];

int main() {
    scanf("%lld%lld", &n, &q);

    while (q-->0) {
        int t;
        scanf("%d", &t);

        if (t == 1) {
            ll x, y, c;
            scanf("%lld%lld%lld", &x, &y, &c);

            if (y < sqrt_n) {
                b[y][x] += c;
            } else {
                for (ll i = x; i <= n; i += y) {
                    a[i] += c;
                }
            }
        } else {
            ll i;
            scanf("%lld", &i);

            ll ret = a[i];
            for (ll y = 1; y < sqrt_n; ++y) {
                ret += b[y][i%y];
            }

            printf("%lld\n", ret);
        }
    }
}
