#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> per_box(t, 1);
    vector<int> a(n);
    for (auto &x : a)cin >> x;
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](auto i, auto j) {
        return a[i] < a[j];
    });
    vector<vector<int>> ans(n);

    for (int i = 0; i < a[idx[0]]; ++i) {
        ans[idx[0]].push_back(0);
        ++per_box[0];
    }

    for (int i = 1; i < n; ++i) {
        int id = idx[i];
        int use = 0;
        for (int j = 0; use < a[id] && j < t; ++j) {
            for (int k = 0; use < a[id] && k < per_box[j]; ++k) {
                ans[id].push_back(j);
                ++use;
            }
        }
        if (use < a[id]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (auto& row : ans) {
        for (auto i : row)cout << i+1 << ' ';
        cout << endl;
    }
}
