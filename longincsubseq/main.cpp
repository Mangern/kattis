#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;

struct BIT {
    int n;
    vector<ii> ft;

    BIT(int _n) {
        n = _n;
        ft = vector<ii>(n, ii{0,-1});
    }

    void set_max(int i, int x, int idx) {
        for (; i < n; i += (i & (-i))) {
            if (x > ft[i][0]) {
                ft[i] = ii{x, idx};
            }
        }
    }

    ii query(int i) {
        ii r = ii{0,-1};
        for (; i; i -= (i & (-i))) {
            r = max(r, ft[i]);
        }
        return r;
    }
};

void testCase(int n) {
    vector<int> a(n);
    vector<ii> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    vector<int> bit_idx(n);
    sort(begin(b), end(b));

    int s = 1;
    for (int i = 0; i < n; ++i) {
        int j = b[i][1];
        if (i == 0 || b[i][0] != b[i-1][0]) {
            bit_idx[j] = s++;
        } else {
            bit_idx[j] = bit_idx[b[i-1][1]];
        }
    }

    vector<int> lis(n, 0);
    vector<int> cf(n, -1);
    int ans = 0;
    int ansi = 0;

    BIT bit(s);
    for (int i = 0; i < n; ++i) {
        int j = bit_idx[i];
        ii best = bit.query(j-1);
        lis[i] = best[0] + 1;
        cf[i] =  best[1];

        bit.set_max(j, lis[i], i);

        if (lis[i] > ans) {
            ans = lis[i];
            ansi = i;
        }
    }
    cout << ans << endl;
    vector<int> path;
    while (ansi != -1) {
        path.push_back(ansi);
        ansi = cf[ansi];
    }
    while (path.size()) {
        cout << path.back() << " ";
        path.pop_back();
    }
    cout << endl;
}

int main() {
    int n;
    while (cin >> n) {
        testCase(n);
    }
}
