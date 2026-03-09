#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 2e5+5;

ll n, f;
ll tree[mxN*4];
ll lazy[mxN*4];

void push(int p, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    lazy[p<<1] += lazy[p];
    tree[p<<1] += lazy[p] * (mid - l + 1);
    lazy[p<<1|1] += lazy[p];
    tree[p<<1|1] += lazy[p] * (r - mid);
    lazy[p] = 0;
    tree[p] = tree[p<<1] + tree[p<<1|1];
}

void range_add(int p, int l, int r, int i, int j, ll val) {
    // cout << "Adding to range " << i << " " << j << " (" << l << " " << r << ") " << endl;
    push(p, l, r);

    if (i <= l && r <= j) {
        if (l == r) {
            tree[p] += val;
            return;
        }
        lazy[p] += val;
        tree[p] += val * (r - l + 1);
        return;
    }

    int mid = (l + r) / 2;

    if (j <= mid) {
        range_add(p<<1, l, mid, i, j, val);
    } else if (mid + 1 <= i) {
        range_add(p<<1|1, mid+1, r, i, j, val);
    } else {
        range_add(p<<1, l, mid, i, mid, val);
        range_add(p<<1|1, mid+1, r, mid+1, j, val);
    }

    tree[p] = tree[p<<1] + tree[p<<1|1];
}
void range_add(int i, int j, ll val) {
    range_add(1, 0, n - 1, i, j, val);
}


ll range_query(int p, int l, int r, int i, int j) {
    // cout << "Query range " << i << " " << j << " (" << l << " " << r << "): " << tree[p] << endl;
    push(p, l, r);
    if (i <= l && r <= j) {
        return tree[p];
    }
    int mid = (l + r) / 2;
    if (j <= mid) {
        return range_query(p<<1, l, mid, i, j);
    } else if (mid + 1 <= i) {
        return range_query(p<<1|1, mid+1, r, i, j);
    } else {
        return range_query(p<<1, l, mid, i, mid) + range_query(p<<1|1, mid+1, r, mid+1, j);
    }
}

ll range_query(int l, int r) {
    return range_query(1, 0, n - 1, l, r);
}

using ii = pair<ll, ll>;

pair<ii, ii> get_ranges(int loc, int num) {
    ll num_left = loc;
    ll num_rigt = n - 1 - loc;
    assert(num_left > 0);
    assert(num_rigt > 0);
    ll half = num / 2;

    if (min(num_left, num_rigt) >= half) {
        return {ii{loc - half, loc - 1}, ii{loc + 1, loc + half}};
    } else if (num_left < half) {
        return {ii{0, loc - 1}, ii{loc + 1, loc + num_left + (num - num_left * 2)}};
    } else if (num_rigt < half) {
        return {ii{loc - num_rigt - (num - num_rigt * 2), loc - 1}, ii{loc + 1, n - 1}};
    } else {
        assert(false);
    }
}

pair<ll, ll> get_avg(ll loc, ll num) {
    if (loc == 0) {
        ll s = range_query(loc+1, loc + num);
        return {s, num};
    } else if (loc == n - 1) {
        ll s = range_query(loc - num, loc - 1);
        return {s, num};
    } else {
        auto [rang1, rang2] = get_ranges(loc, num);
        auto [l1, r1] = rang1;
        auto [l2, r2] = rang2;
        ll s = range_query(l1, r1) + range_query(l2, r2);
        return {s, num};
    }
}

void apply_cams(int loc, int num, ll m) {
    if (loc == 0) {
        range_add(loc+1, loc + num, m);
    } else if (loc == n - 1) {
        range_add(loc - num, loc - 1, m);
    } else {
        auto [rang1, rang2] = get_ranges(loc, num);
        auto [l1, r1] = rang1;
        auto [l2, r2] = rang2;
        range_add(l1, r1, m);
        range_add(l2, r2, m);
    }
}

int main() {
    cin >> n >> f;

    for (int i = 0; i < f; ++i) {
        ll m, loch, h, locv, v;
        cin >> m >> loch >> h >> locv >> v;
        --loch, --locv;

        auto [numh, denh] = get_avg(loch, h);
        auto [numv, denv] = get_avg(locv, v);
        // numh / denh <= numv / denv
        // numh * denv <= numv * denh
        if (numh * denv <= numv * denh) {
            apply_cams(loch, h, m);
        } else {
            apply_cams(locv, v, m);
        }
    }

    int q;
    cin >> q;
    while (q-->0) {
        ll l, r;
        cin >> l >> r, --l, --r;
        cout << range_query(l, r) << '\n';
    }
}
