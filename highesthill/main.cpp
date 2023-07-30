#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mxN = 2e5+4;

int n;
ll h[mxN];
ll l[mxN];
ll r[mxN];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)cin >> h[i];

    int lo = 0;

    l[0] = 0;

    for (int i = 1; i < n; ++i) {
        if (h[i] < h[i-1]) {
            l[i] = i;
        } else {
            l[i] = l[i-1];
        }
    }

    r[n-1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (h[i] < h[i+1])r[i] = i;
        else r[i] = r[i+1];
    }

    ll ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (l[i] < i && r[i] > i) {
            ans = max(ans, min(h[i] - h[l[i]], h[i] - h[r[i]]));
        }
    }
    cout << ans << endl;
}
