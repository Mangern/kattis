#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<ll> divs;
    ll n;
    cin >> n;

    for (ll d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            divs.push_back(d);
            if (d * d < n)divs.push_back(n/d);
        }
    }
    sort(begin(divs),end(divs));
    for (auto d : divs)printf("%lld ",d);
    puts("");
}
