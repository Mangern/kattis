#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template<typename t = long long>
struct FenwickTree {
    int n;
    vector<t> tree;
    FenwickTree(int _n) {
        n = _n+1;
        tree = vector<t>(n, t(0));
    }

    t query(int i) {
        ++i;

        t sum(0);
        for (; i > 0; i -= (i & (-i)))sum += tree[i];
        return sum;
    }

    t query(int i, int j) {
        return query(j) - query(i-1);
    }

    void add(int i, t val) {
        ++i;
        for (; i < n; i += (i & (-i))) {
            tree[i] += val;
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    FenwickTree<int> fts[6] = {
        FenwickTree<int>(n),
        FenwickTree<int>(n),
        FenwickTree<int>(n),
        FenwickTree<int>(n),
        FenwickTree<int>(n),
        FenwickTree<int>(n)
    };

    vector<ll> vs(6, 0);
    for (auto& v : vs)cin >> v;

    string ps;
    cin >> ps;
    
    vector<int> tp(n, 0);

    for (int i = 0; i < n; ++i) {
        fts[ps[i] - '1'].add(i, 1);
        tp[i] = ps[i] - '1';
    }

    while (q-->0) {
        int t;
        cin >> t;

        if (t == 1) {
            int k, p;
            cin >> k >> p;
            --k, --p;
            int cur = tp[k];

            fts[cur].add(k, -1);
            fts[p].add(k, 1);

            tp[k] = p;
        } else if (t == 2) {
            int p, v;
            cin >> p >> v;
            vs[p-1] = v;
        } else {
            int l, r;
            cin >> l >> r, --l, --r;
            ll sm = 0;

            for (int i = 0; i < 6; ++i) {
                sm += vs[i] * (ll)fts[i].query(l, r);
            }
            cout << sm << endl;
        } 
    }
}
