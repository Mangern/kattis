#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, h, c;
    cin >> n >> h >> c;

    vector<vector<ll>> cands(n);
    for (auto &v : cands) {
        v.resize(h);
        for (auto &x : v) cin >> x;
        sort(begin(v), end(v));
    }
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);

    bool done = 0;
    ll tot = 0;
    int ans = 0;
    for (int it = 0; it < h && !done; ++it) {
        sort(begin(idx), end(idx), [&] (int i1, int i2) {
            return cands[i1][it] < cands[i2][it];
        });

        for (int i : idx) {
            if (tot + cands[i][it] > c) {
                done = true;
                break;
            }
            tot += cands[i][it];
            ++ans;
        }
    }
    cout << ans << endl;
}
