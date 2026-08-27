#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

int main() {
    ll n, a,b;
    scanf("%lld%lld%lld", &n, &a, &b);

    ll ab = a * b / gcd(a,b);

    ll fi = 0, bu = 0, fibu = 0;

    for (ll i = 1; i <= n; ++i) {
        if (i % ab== 0)++fibu;
        else if (i % a == 0)++fi;
        else if (i % b == 0)++bu;
    }
    printf("%lld %lld %lld\n", fi, bu, fibu);
    return 0;
}
