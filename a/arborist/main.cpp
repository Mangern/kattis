#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);

    vector<int> x(n), w(n);
    for (auto &y : x) cin >> y;
    for (auto &y : w) cin >> y;

    int ans = 1000000000;
    do {
        int cur = 0;
        for (int i = 0; i < n; ) {
            if (i + 1 < n && w[idx[i]] + w[idx[i+1]] <= k) {
                cur += 4;
                int dist = max(x[idx[i]], x[idx[i+1]]);
                cur += 2 * dist;

                i += 2;
            } else {
                cur += 2;
                int dist = x[idx[i]];
                cur += 2 * dist;

                i += 1;
            }
        }
        ans = min(ans, cur);
    } while (next_permutation(begin(idx), end(idx)));
    cout << ans << endl;
}
