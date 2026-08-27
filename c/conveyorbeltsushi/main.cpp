#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    vector<int> c(m);
    for (auto &x : c) cin >> x;

    int n, q;
    cin >> n >> q;

    int curm = 0;
    vector<int> belt(n+1,-1);

    auto step = [&] () {
        vector<int> nbelt(n+1,-1);
        for (int i = 0; i <= n; ++i) {
            nbelt[(i+1)%(n+1)] = belt[i];
        }
        belt=nbelt;
        if (belt[0] == -1) {
            belt[0] = curm;
            curm = (curm + 1) % m;
        }
    };

    vector<int> bill(n, 0);

    int pt = 0;

    while (q-->0) {
        int t, p;
        cin >> t >> p, --p;
        for (int i = 0; i < t - pt; ++i) {
            step();
        }

        assert(belt[p] != -1);

        bill[p] += c[belt[p]];
        belt[p] = -1;

        pt = t;
    }

    for (int i = 0; i < n; ++i) {
        cout << bill[i] << endl;
    }
}
