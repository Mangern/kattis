#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+5;
const int INF = 1e9+1;

int st[4*mxN];

void update(int p, int l, int r, int idx, int x) {
    if (l == r) {
        st[p] = x;
        return;
    }

    int mid = (l + r) / 2;
    if (idx <= mid) {
        update(p<<1, l, mid, idx, x);
    } else {
        update(p<<1|1, mid+1, r, idx, x);
    }
    st[p] = min(st[p<<1], st[p<<1|1]);
}

int query(int p, int l, int r, int i, int j) {
    if (i <= l && r <= j) {
        return st[p];
    }
    if (j < l) return INF;
    if (r < i) return INF;
    int mid = (l+r) / 2;
    return min(query(p<<1, l, mid, i, j), query(p<<1|1, mid+1, r, i, j));
}

int main() {
    int n, q;
    cin >> n >> q;
    while (q-->0) {
        char t;
        cin >> t;
        if (t == 'U') {
            int i, x;
            cin >> i >> x;
            update(1, 0, n - 1, i-1, x);
        } else {
            int l, r;
            cin >> l >> r, --l, --r;
            cout << query(1, 0, n - 1, l, r) << '\n';
        }
    }
}
