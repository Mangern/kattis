#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    ll m;
    cin >> m;

    ll ans = 0;

    ll cnt = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == 'A') {
            ll swp = min(m, cnt);
            ans += cnt - swp;
            m -= swp;
        } else ++cnt;
    }
    cout << ans << endl;
}
