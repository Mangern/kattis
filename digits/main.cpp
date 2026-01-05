#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dlen(ll n) {
    ll d = 0;
    while (n) {
        ++d;
        n /= 10;
    }
    return d;
}

int main() {
    for (;;) {
        string s;
        cin >> s;
        if (s == "END") break;
        ll n = s.length();

        if (n == 1 && s == "1") {
            cout << 1 << endl;
            continue;
        }

        for (ll i = 2; ;++i) {
            ll nxt = dlen(n);

            if (nxt == n) {
                cout << i << endl;
                break;
            }
            n = nxt;
        }
    }
}
