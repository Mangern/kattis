#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<ll> comb(const set<ll>& sa, const set<ll>& sb) {
    set<ll> res;
    for (auto s : sa) {
        for (auto t : sb) {
            res.insert(s + t);
            res.insert(s - t);
            res.insert(t - s);
            res.insert(s * t);
            if (t>0 && s % t == 0)res.insert(s/t);
            if (s>0 && t % s == 0)res.insert(t/s);
        }
    }
    return res;
}

set<ll> cr1(ll a) {
    return set<ll>{a};
}

set<ll> cr2(ll a, ll b) {
    auto sa = cr1(a);
    auto sb = cr1(b);

    return comb(sa,sb);
}

set<ll> cr3(ll a, ll b, ll c) {
    auto sab = cr2(a,b);
    auto sac = cr2(a,c);
    auto sbc = cr2(b,c);
    auto resab = comb(sab, cr1(c));
    auto resac = comb(sac, cr1(b));
    auto resbc = comb(sbc, cr1(a));

    set<ll> res = {a,b,c};
    for (auto x : sab)res.insert(x);
    for (auto x : sac)res.insert(x);
    for (auto x : sbc)res.insert(x);
    for (auto x : resab)res.insert(x);
    for (auto x : resac)res.insert(x);
    for (auto x : resbc)res.insert(x);
    return res;
}

int main() {
    srand(69);
    map<ll, array<ll,3>> ans;
    set<ll> rem;
    for (ll i = 1; i <= 100; ++i)rem.insert(i);

    while (rem.size()) {
        ll a = rand() % 100 + 1;
        ll b = a;
        ll c = a;

        while (b == a) {
            b = rand() % 100 + 1;
        }
        while (c == b || c == a) {
            c = rand() % 100 + 1;
        }

        auto s = cr3(a,b,c);

        for (ll i = 1; i <= 100; ++i) if (rem.count(i)) {
            if (!s.count(i)) {
                rem.erase(i);
                ans[i] = {a,b,c};
            }
        }
    }

    ll d;
    cin >> d;

    auto [a,b,c] = ans[d];
    cout << a << " " << b << " " << c << endl;
}
