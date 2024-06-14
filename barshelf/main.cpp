#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <map>

using namespace std;
using ll = long long;

const int mxN = 2e5+5;

template<typename T>
struct BIT {
    vector<T> tree;
    BIT(int n) {
        tree = vector<T>(n+1, 0);
    }

    // O(n lg n)
    BIT(vector<T> a) {
        BIT(a.size());
        for (int i = 0; i < a.size(); ++i) {
            update(i, a[i]);
        }
    }

    // Returns sum of elements from index 0 to index i (inclusive)
    // 0-indexed
    // O(lg n)
    T rsq(int i) {
        ++i;
        i = min(i, (int)tree.size() - 1);
        T sum(0);

        for (; i > 0; i -= (i & (-i)))sum += tree[i];
        return sum;
    }

    // Returns sum of elements from index l to index r (inclusive)
    // 0-indexed
    // O(lg n)
    T rsq(int l, int r) {
        return rsq(r) - rsq(l - 1);
    }

    void update(int i, T v) {
        ++i;
        for(; i < tree.size(); i += (i & (-i)))tree[i] += v;
    }
};


int n;
map<ll, int> idx;
ll a[mxN];
ll b[mxN];
ll gt[mxN]; // # els to the left >= 2*n

int main() {
    scanf("%d", &n);

    BIT<ll> ft(n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);

        b[i] = a[i];
    }
    sort(b, b+n);

    for (int i = 0; i < n; ++i) {
        if (!idx.count(b[i]))idx[b[i]] = i;
    }

    for (int i = 0; i < n; ++i) {

        auto it = idx.lower_bound(2 * a[i]);

        if (it != idx.end()) {
            gt[i] = i - ft.rsq(it->second - 1);
        }


        ft.update(idx[a[i]], 1);
    }

    BIT<ll> ft2(n);

    ll ans = 0;
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        auto it = idx.lower_bound(2 * a[i]);

        if (it != idx.end()) {
            ans += tot - ft2.rsq(it->second - 1);
        }

        ft2.update(idx[a[i]], gt[i]);
        tot += gt[i];
    }

    printf("%lld\n", ans);

}
