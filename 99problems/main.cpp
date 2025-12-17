#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll above,below;
    for (below = n; below >= 0; --below) {
        if (below % 100 == 99)break;
    }
    for (above = n; ;++above) {
        if (above % 100 == 99) break;
    }
    ll ans = above;
    if (below > 0 && n - below < above - n) ans=below;
    cout << ans << endl;
}
