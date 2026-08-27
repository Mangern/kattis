#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e7+7;

char isp[mxN];

int main() {
    memset(isp, 1, sizeof isp);
    ll s = 0;
    ll n;
    cin >> n;
    for (ll i = 2; i < n; ++i) {
        if (!isp[i]) continue;
        s += i;
        for (ll j = i * i; j < n; j += i) {
            isp[j] = 0;
        }
    }

    cout << s << endl;
}
