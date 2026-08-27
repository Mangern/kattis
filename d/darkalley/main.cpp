#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mxN = 2e5+5;
const ll MOD = 1000000007;

struct node {
    ll base;
    ll baseip;
};

int n, q;
bool has_val[4 * mxN];
node lazy[4 * mxN];
ll val[mxN];

ll mpp[mxN];
ll mip[mxN];

ll mpow(ll a, ll b) {
    if (b == 0) return 1;

    ll r = mpow(a, b >> 1);
    r = (r * r) % MOD;
    if (b & 1) r = (r * a) % MOD;
    return r;
}

ll mmow(bool isip, ll b) {
    return isip ? mip[b] : mpp[b];
}

void push(int p, int l, int r) {
    if (!has_val[p]) return;
    if (l == r) {
        val[l] += lazy[p].base;
        val[l] %= MOD;
        val[l] += lazy[p].baseip;
        val[l] %= MOD;
        lazy[p].base = 0;
        lazy[p].baseip = 0;
        has_val[p] = 0;
        return;
    }

    int lft = (p<<1);
    int rgt = (p<<1|1);
    int mid = (l + r)/2;

    lazy[lft].base += lazy[p].base;
    lazy[lft].base %= MOD;
    lazy[lft].baseip += lazy[p].baseip;
    lazy[lft].baseip %= MOD;
    has_val[lft] = 1;

    lazy[rgt].base += (lazy[p].base * mmow(0, mid + 1 - l)) % MOD;
    lazy[rgt].base %= MOD;

    lazy[rgt].baseip += (lazy[p].baseip * mmow(1, mid + 1 - l)) % MOD;
    lazy[rgt].baseip %= MOD;
    has_val[rgt] = 1;

    lazy[p].base = 0;
    lazy[p].baseip = 0;
    has_val[p] = 0;
}

void upd(int p, int l, int r, int i, int j, ll b, bool isip) {
    push(p, l, r);

    if (j < l) return;
    if (i > r) return;

    if (i <= l && r <= j) {
        ll nb = (b * mmow(isip, l - i)) % MOD;
        if (isip) {
            lazy[p].baseip = nb;
        } else {
            lazy[p].base = nb;
        }
        has_val[p] = 1;
        return;
    }

    int mid = (l + r) / 2;

    upd(p<<1, l, mid, i, j, b, isip);
    upd(p<<1|1, mid+1, r, i, j, b, isip);
}

ll query(int p, int l, int r, int idx) {
    push(p, l, r);

    if (l == r) {
        return val[l];
    }

    int mid = (l + r) / 2;

    if (idx <= mid) {
        return query(p<<1, l, mid, idx);
    } else {
        return query(p<<1|1, mid + 1, r, idx);
    }
}

ll toint(string pval) {
    int dpos = pval.find('.');
    string rem = pval.substr(dpos+1);
    ll num = stoll(rem);
    ll den = mpow(10, rem.length());
    // 1 - p/q
    // (q - p) / q
    num = ((den - num)%MOD + MOD)%MOD;
    return (num * mpow(den, MOD - 2)) % MOD;
}

int main() {
    cin >> n >> q;

    string ps;
    cin >> ps;
    ll p = toint(ps);
    ll ip = mpow(p, MOD - 2);

    mpp[0] = 1;
    mip[0] = 1;

    for (int i = 1; i < n; ++i) {
        mpp[i] = (mpp[i-1] * p) % MOD;
        mip[i] = (mip[i-1] * ip) % MOD;
    }

    while (q-->0) {
        char c;
        cin >> c;

        if (c == '+') {
            ll b, x;
            cin >> b >> x, --x;

            // b * mul^x ...   b * mul^2,  b * mul, b, b * mul
            //   0               x-2       x-1      x , x + 1
            upd(1, 0, n - 1, x, n - 1, b, 0);
            if (x > 0) {
                ll nb = (b * mmow(0, x)) % MOD;
                upd(1, 0, n - 1, 0, x - 1, nb, 1);
            }
        } else if (c == '-') {
            ll b, x;
            cin >> b >> x, --x;
            b = (MOD - b);
            upd(1, 0, n - 1, x, n - 1, b, 0);
            if (x > 0) {
                ll nb = (b * mmow(0, x)) % MOD;
                upd(1, 0, n - 1, 0, x - 1, nb, 1);
            }
        } else {
            int idx;
            cin >> idx;
            --idx;
            cout << query(1, 0, n - 1, idx) << endl;
        }
    }
}
