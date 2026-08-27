#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, R;
    cin >> n >> k >> R;

    vector<vector<int>> idx(k, vector<int>());
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    vector<int> rec(k, -1);

    for (int i = 0; i < R; ++i) {
        int x, y;
        cin >> x >> y;
        rec[x] = y;
    }
    map<int, int> window;
    int done = 0;

    int r;
    for (r = 0; r < n; ++r) {
        if (rec[a[r]] == -1) continue;
        if (++window[a[r]] == rec[a[r]]) {
            if (++done == R) break;
        }
    }

    if (r == n) {
        cout << "impossible" << endl;
        return 0;
    }
    ++r;
    int l = -1;
    int ans = n;
    for (; r <= n; ++r) {
        for (;;) {
            if (rec[a[l+1]] == -1) {
                ++l;
                continue;
            }
            if (window[a[l+1]] == rec[a[l+1]]) break;
            --window[a[l+1]];
            ++l;
        }
        ans = min(ans, r - l - 1);
        if (r == n) break;
        if (rec[a[r]] != -1) {
            ++window[a[r]];
        }
    }
    cout << ans << endl;
}
