#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll revbit(ll n) {
    ll res = 0;
    while (n>0) {
        res <<= 1;
        res |= (n&1);
        n >>= 1;
    }
    return res;
}

ll revdig(ll n) {
    ll res = 0;
    while (n>0) {
        res *= 10;
        res += (n%10);
        n /= 10;
    }
    return res;
}

ll b10len(ll n) {
    ll res = 0;
    while (n>0) {
        ++res;
        n /= 10;
    }
    return res;
}

bool isb2(ll x) {
    return x == revbit(x);
}

int main() {
    ll n;
    cin >> n;


    ll nlen = b10len(n);

    ll ans = 1;
    ll top = 1;
    if (n > 1)++ans;
    if (n > 3)++ans;
    if (n > 5)++ans;
    if (n > 7)++ans;
    if (n > 9)++ans;

    set<ll> found;

    for (ll l = 1; l * 2 <= nlen; ++l) {
        // even length: l l
        top *= 10;
        for (ll i = top/10; i < top; ++i) {
            // i rev(i)
            if (i * top >= n) break;
            ll x = i * top + revdig(i);
            if (x >= n) continue;
            if (isb2(x)) {
                ++ans;
                // cout << "Good(e): " << x << " " << bitset<22>(x) << endl;
                // found.insert(x);
            }
        }

        if (l * 2 + 1 <= nlen) {
            // odd length: l dig l
            for (ll dig = 0; dig < 10; ++dig) {
                for (ll i = top/10; i < top; ++i) {
                    if (i * top * 10 + dig * top >= n) break;
                    ll x = i * top * 10 + dig * top + revdig(i);
                    if (x >= n) continue;
                    if (x >= n) continue;
                    if (isb2(x)) {
                        ++ans;
                        // cout << "Good(o): " << x << " " << bitset<22>(x) << endl;
                        // found.insert(x);
                    }
                }
            }
        }
    }

    // for (ll i = 10; i < n; ++i) {
    //     if (!isb2(i))continue;
    //     ll r = revdig(i);
    //     if (i != r) continue;
    //
    //     if (!found.count(i)) {
    //         cout << "Missed: " << i << " " << bitset<22>(i) << endl;
    //     }
    // }

    cout << ans << endl;
}
