#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int,vector<int>> idxs;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        idxs[a[i]%k].push_back(i);
    }
    vector<int> b(n);
    for (auto &[_, v] : idxs) {
        auto orig = v;
        sort(begin(v), end(v), [&](auto i, auto j) {
            return a[i] < a[j];
        });

        int ptr = 0;
        for (auto i : v) {
            b[orig[ptr++]] = a[i];
        }
    }

    for (int i = 1; i < n; ++i) {
        if (b[i] < b[i-1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
