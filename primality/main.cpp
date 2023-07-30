#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B = 1234567891234567895) {
    ll r = 0;
    while (!r)r = (unsigned ll)rng() % B;
    return r;
}

ll p;

ll gcd(ll a, ll b) {
    if (b == 0)return a;
    return gcd(b,a%b);
}

ll modpow(ll a, ll b) {
    a %= p;
    b %= p - 1;
    if (b == 0)return 1;
    ll r = modpow(a,b>>1LL);
    r = (r * r) % p;
    if (b & 1LL)r = (r * a) % p;
    return r;
}

int main() {
    cin >> p;

    if (p == 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (p % 2 == 0) {
        cout << (p == 2 ? "YES" : "NO") << endl;
        return 0;
    }

    if (p % 3 == 0) {
        cout << (p == 3 ? "YES" : "NO") << endl;
        return 0;
    }
    if (p % 5 == 0) {
        cout << (p == 5 ? "YES" : "NO") << endl;
        return 0;
    }
    if (p % 7 == 0) {
        cout << (p == 7 ? "YES" : "NO") << endl;
        return 0;
    }

    ll d = p-1;
    ll s = 0;
    while (d % 2 == 0) {
        ++s;
        d >>= 1LL;
    }


    vector<ll> tests = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (int i = 0; i < 100000; ++i)tests.push_back(myRand(p-1));
    for (ll a : tests) {


        ll g = gcd(a,p);
        if (g != 1 && g != p) {
            cout << "NO" << endl;
            return 0;
        }

        if (a >= p)continue;

        ll r = modpow(a,d);
        bool compo = true;
        if (r == 1) {
            compo = false;
        }

        r = 1;
        for (int j = 0; compo && j < s; ++j) {
            ll x = modpow(a,r*d);
            if (x == p - 1) {
                compo = false;
            }
            r *= 2LL;
        }

        if (compo) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
