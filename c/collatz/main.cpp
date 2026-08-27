#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void testCase() {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    if (!a)exit(0);

    ll oa = a;
    ll ob = b;

    map<ll, ll> ina;
    ll sta = 0;
    while (true) {
        ina[a] = sta;
        if (a == 1) break;
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a *= 3;
            a += 1;
        }
        ++sta;
    }

    ll stb = 0;
    while (true) {
        if (ina.count(b)) break;
        if (b % 2 == 0) {
            b /= 2;
        } else {
            b *= 3;
            b += 1;
        }
        ++stb;
    }

    printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", oa, ina[b], ob, stb, b);
}

int main() {
    while (true) testCase();
    return 0;
}
