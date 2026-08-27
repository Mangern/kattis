#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);

    multiset<ll> ms;
    for (int i = 0; i < k; ++i) {
        ll x;
        scanf("%lld", &x);
        ms.insert(x);
    }

    for (int i = 0; i < n; ++i) {
        char c;
        scanf("%c", &c);
        scanf("%c", &c);
        if (c == 'C') {
            ll x;
            scanf("%lld", &x);
            ms.insert(x);
        } else if (c == 'S') {
            ll x = *--ms.end();
            ms.erase(--ms.end());
            printf("%lld\n", x);
        } else {
            ll x = *ms.begin();
            ms.erase(ms.begin());
            printf("%lld\n", x);
        }
    }
}
