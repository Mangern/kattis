#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;
const ll INF = numeric_limits<ll>::max() / 4;

struct SegmentTree {
    ll sz;
    vector<ll> tree;
    SegmentTree(ll n) { 
        sz=1;
        while (sz < n) {
            sz <<= 1;
        }
        tree = vector<ll>(2*sz, INF);
    }

    // set i to x
    void update(ll i, ll x) {
        i += sz;
        tree[i] = x;
        while (i > 1) {
            i >>= 1;
            tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    ll first_smaller(ll x) {
        ll i = 1;
        while (i < sz) {
            if (tree[i * 2] < x) {
                i *= 2;
            } else {
                i *= 2;
                ++i;
            }
        }
        return i - sz;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    if (n < 4) {
        cout << "Ekkert mynstur!\n";
        return;
    }

    vector<ll> pfmin(n), sufmax(n);
    pfmin[0] = 0;
    for (ll i = 1; i < n; ++i) {
        if (a[i] < a[pfmin[i-1]])pfmin[i] = i;
        else pfmin[i] = pfmin[i-1];
    }
    sufmax[n-1] = n - 1;
    for (ll i = n - 2; i >= 0; --i) {
        if (a[i] > a[sufmax[i+1]])sufmax[i] = i;
        else sufmax[i] = sufmax[i+1];
    }

    SegmentTree st(n);

    st.update(n - 2, a[n-2]);

    for (ll i = n - 3; i > 0; --i) {
        // i is candidate for '3'
        ll i1 = pfmin[i-1];
        ll i3 = i;
        if (a[i1] > a[i3]) continue;
        // pfmin[i-1] plays '1'

        // now, efficiently find "next between '1' and '3'"
        // notice that the 1s we get are forming a non-decreasing sequence
        ll i2 = -1;
        for (;;) {
            i2 = st.first_smaller(a[i3]);
            if (i2 >= n - 1) break;
            if (a[i2] < a[i1]) {
                st.update(i2, INF);
                continue;
            }
            break;
        }

        if (i < i2 && i2 < n - 1) {
            assert(a[i2] < a[i3] && a[i2] > a[i1]);
            ll i4 = sufmax[i2+1];
            if (a[i4] > a[i3]) {
                cout << i1+1 << " " << i3+1 << " " << i2+1 << " " << i4+1 << "\n";
                return;
            }
        }
        st.update(i, a[i]);
    }
    cout << "Ekkert mynstur!\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t-->0) {
        solve();
    }
}
