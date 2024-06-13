#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

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

void solve() {
    int m, r;
    cin >> m >> r;
    FenwickTree<long long> ft(m + r);

    for (int i = 0; i < m; ++i)ft.add(r+i, 1);

    vector<int> pos(m);
    for (int i = 0; i < m; ++i)pos[i] = r+i;

    for (int i = 1; i <= r; ++i) {
        int a;
        cin >> a, --a;
        int cur = ft.query(pos[a] - 1);
        cout << cur << " \n"[i == r];
        ft.add(pos[a], -1);
        pos[a] = r-i;
        ft.add(pos[a], 1);
    }
}

int main() {
    int t;
    cin >> t;
    while (t-->0)solve();
}
