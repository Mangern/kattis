#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isp(ll x) {
    if (x <= 5) {
        return x == 2 || x == 3 || x == 5;
    }
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

string nxt(string s) {
    ll r=0;
    for (char c : s) {
        r *= 26;
        r += c - 'A';
    }
    ++r;
    string ret(3, '?');

    for (int i = 2; i >= 0; --i) {
        ret[i] = 'A' + r % 26;
        r /= 26;
    }
    return ret;
}

int main() {
    vector<ll> primes;
    for (ll i = 2; i < 10000; ++i) if (isp(i))primes.push_back(i);

    for (;;) {
        string s;
        cin >> s;
        ll n;
        cin >> n;

        if (s == "END" && n == 0) break;

        auto it = lower_bound(begin(primes), end(primes), n);
        string anss = s;
        ll ans = -1;
        if (it == end(primes)) {
            anss = nxt(s);
            ans = 2;
        } else {
            ans = *it;
        }

        printf("%s %04d\n", anss.c_str(), (int)ans);
    }
}
