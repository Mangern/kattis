#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int mxN = 1e5+5;

int a[mxN];
int p[mxN];

struct cmp {
    bool operator()(const int& x, const int& y) const {
        if (a[x] == a[y] && p[x] == p[y])return x < y;
        if (a[x] == a[y])return p[x] < p[y];
        return a[x] > a[y];
    }
};

typedef tree<int, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
    ost st;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)st.insert(i);

    for (int i = 0; i < m; ++i) {
        int t, pen;
        cin >> t >> pen;
        --t;

        st.erase(st.find(t));
        ++a[t];
        p[t] += pen;
        st.insert(t);

        cout << st.order_of_key(0) + 1 << endl;
    }
}
