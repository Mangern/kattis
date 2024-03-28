#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

int n;

ll a[mxN];

ll msb(ll x) {
    int msb = 0;
    while (x) {
        ++msb;
        x >>= 1;
    }
    return msb;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i)cin >> a[i];

    for (ll bit = 60; bit >= 0; --bit) {
        ll mx = -1;
        int mxi = -1;

        for (int i = 0; i < n; ++i) {
            if (msb(a[i]) == bit) {
                if (a[i] > mx)mxi = i;
                mx = max(mx, a[i]);
            }
        }
        if (mx == -1)continue;

        for (int i = 0; i < n; ++i) if (i != mxi){
            if (msb(a[i]) == bit)a[i] ^= mx;
        }
    }

    sort(a,a+n);

    ll ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        if ((ans ^ a[i]) > ans)ans ^= a[i];
    }
    cout << ans << endl;

    return 0;
}

