#include <stdio.h>
typedef long long ll;

int main() {
    ll a, b, c,d;

    int tc = 1;
    while (scanf("%lld", &a) != EOF) {
        scanf("%lld%lld%lld", &b, &c, &d);

        printf("Case %d:\n", tc++);

        ll ia = d;
        ll ib = -b;
        ll ic = -c;
        ll id = a;
        ll g = a * d - b * c;
        ia /= g;
        ib /= g;
        ic /= g;
        id /= g;

        printf("%lld %lld\n", ia, ib);
        printf("%lld %lld\n", ic, id);
    }
}
