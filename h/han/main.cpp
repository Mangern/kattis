#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q;
    bool rev = 0;
    cin >> q;

    ll cur = 0;
    ll pos = -1;

    auto travel = [&] (ll n) {
        ll delta = (n - cur);

        ll rounds = delta / 26;
        for (int i = 0; i < 26; ++i) {
            cnt[i] += rounds;
        }

        for (int i = 0; i < delta % 26; ++i) {
            if (rev)pos += 25; 
            else pos += 1;
            pos %= 26;
            ++cnt[pos];
        }
        cur = n;
    };

    while (q-->0) {
        string ord;
        cin >> ord;
        ll n;
        cin >> n;

        if (ord[0] == 'U') {
            travel(n);
            char c;
            cin >> c;
            cout << cnt[c-'a'] << "\n";
        } else {
            travel(n);
            rev = !rev;
        }
    }
}
