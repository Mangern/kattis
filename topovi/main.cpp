#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;
using tup = array<ll, 3>;
using quad = array<ll, 4>;

const int mxN = 600005;

ll n, k, p;

vector<ll> unq;

ll ans;
ll rowval[mxN];
ll colval[mxN];
ll rowtot = 0;
ll coltot = 0;
unordered_map<ll, ll> rowcnt, colcnt;
map<ii, ll> curval;

ll lookup(ll x) {
    return lower_bound(begin(unq), end(unq), x) - begin(unq);
}

void setcol(ll c, ll x) {
    // contribution: n - amount of rows with x as value
    ans += n - rowtot; // 0 -> x
    ans -= rowcnt[x];  // x -> 0
    colval[c] = x;
    ++coltot;
    ++colcnt[x];
}

void unsetcol(ll c) {
    ll x = colval[c];
    ans -= n - rowtot; // x -> 0
    ans += rowcnt[x]; // 0 -> x
    --colcnt[x];
    --coltot;
    colval[c] = 0;
}

void setrow(ll r, ll x) {
    ans += n - coltot;
    ans -= colcnt[x];
    rowval[r] = x;
    ++rowtot;
    ++rowcnt[x];
}

void unsetrow(ll r) {
    ll x = rowval[r];
    ans -= n - coltot;
    ans += colcnt[x];
    --rowcnt[x];
    --rowtot;
    rowval[r] = 0;
}

void applycol(ll c, ll x) {
    if (colval[c] == 0) {
        setcol(c, x);
    } else if (colval[c] == x) {
        unsetcol(c);
    } else {
        ll y = colval[c] ^ x;
        unsetcol(c);
        setcol(c, y);
    }
}

void applyrow(ll r, ll x) {
    if (rowval[r] == 0) {
        setrow(r, x);
    } else if (rowval[r] == x) {
        unsetrow(r);
    } else {
        ll y = rowval[r] ^ x;
        unsetrow(r);
        setrow(r, y);
    }
}

int main() {
    cin >> n >> k >> p;

    vector<tup> init(k);
    for (auto &[r, c, x] : init) {
        cin >> r >> c >> x;
        unq.push_back(r);
        unq.push_back(c);
    }

    vector<quad> query(p);
    for (auto &[r1, c1, r2, c2] : query) {
        cin >> r1 >> c1 >> r2 >> c2;
        unq.push_back(r1);
        unq.push_back(c1);
        unq.push_back(r2);
        unq.push_back(c2);
    }
    sort(begin(unq), end(unq));
    unq.erase(unique(begin(unq), end(unq)), end(unq));

    for (auto [r, c, x] : init) {
        r = lookup(r);
        c = lookup(c);
        applyrow(r, x);
        applycol(c, x);
        curval[{r, c}] = x;
    }

    for (auto [r1, c1, r2, c2] : query) {
        r1 = lookup(r1);
        c1 = lookup(c1);
        r2 = lookup(r2);
        c2 = lookup(c2);

        ll x = curval[{r1, c1}];

        applyrow(r1, x);
        applycol(c1, x);
        applyrow(r2, x);
        applycol(c2, x);
        curval[{r2, c2}] = x;

        cout << ans << '\n';
    }
}
