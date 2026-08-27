#include <iostream>

using namespace std;
using ll = long long;

const int mxN = 5e6+5;

int n, q;
ll ft[mxN];


void add(ll i, ll v) {
    for (; i < mxN; i += (i & (-i))) {
        ft[i] += v;
    }
}

ll rsq(ll i) {
    ll s = 0;
    for (; i > 0; i -= (i & (-i))) {
        s += ft[i];
    }
    return s;
}

int main() {
    scanf("%d %d", &n, &q);
    while (q-->0) {
        char c;
        scanf(" %c", &c);

        if (c == '+') {
            ll i, v;
            scanf("%lld %lld", &i, &v);
            add(i+1, v);
        } else {
            ll i;
            scanf("%lld", &i);
            printf("%lld\n", rsq(i));
        }
    }
}
