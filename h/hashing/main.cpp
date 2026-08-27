#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxN = 3e5+6;


template<ll P = 911382323, ll M = 972663749>
struct Hash {
    ll modpow(ll a, ll b) {
        if (b == 0) return 1;
        ll r = modpow(a, b >> 1);
        r = (r * r) % M;
        if (b & 1) r = (r * a) % M;
        return r;
    }

    ll inv(ll x) {
        x %= M;
        return modpow(x, M - 2);
    }

    vector<ll> h, p;
    Hash(string s) {
        int n = s.length();
        h.resize(n+1);
        p.resize(n+1);
        p[0] = 1;
        h[0] = 0;
        for (int i = 1; i <= n; ++i) {
            p[i] = (p[i-1] * P) % M;
        }

        for (int i = 1; i <= n; ++i) {
            if (i > 0)h[i] = h[i-1];

            h[i] = (h[i] + s[i-1] * p[i] % M) % M;
        }
    }

    ll hash(int l, int r) {
        ll s = ((h[r] - h[l]) % M + M) % M;
        return (s * inv(p[l])) % M;
    }
};

string s;
int n;
ll h[mxN];
ll p[mxN]; // p^i

int main() {
    cin >> s;
    n = s.length();

    Hash ha(s);
    Hash<311, (ll)(1e9+7)> hb(s);

    int q;
    cin >> q;

    while (q --> 0) {
        int l, r;
        cin >> l >> r;

        unsigned long long x = ha.hash(l, r);
        unsigned long long y = hb.hash(l, r);
        unsigned long long h = (x << 32) | y;
        cout << h << endl;
    }
}
