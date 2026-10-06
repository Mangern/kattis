#include <bits/stdc++.h>
using namespace std;

#define all(v) begin(v), end(v)

int n, k;
int main() {
    cin >> n >> k;

    unordered_map<string, vector<int>> idxs;

    for (int i = 0; i < k; ++i) {
        int idx; string s;
        cin >> idx >> s;

        idxs[s].push_back(idx);
    }

    for (auto &[k, v] : idxs) {
        sort(all(v));
    }

    int m;
    cin >> m;
    vector<string> a(m);
    for (auto &s : a) cin >> s;

    int ptr = 0;

    vector<int> o1;
    for (const auto& s : a) {
        const auto& cur = idxs[s];
        auto it = lower_bound(all(cur), ptr);
        if (it == end(cur)) {
            cout << "impossible" << endl;
            return 0;
        }
        ptr = *it;
        o1.push_back(ptr);
    }

    ptr = n - 1;
    vector<int> o2;
    for (int i = m - 1; i >= 0; --i) {
        const auto& s = a[i];
        const auto& cur = idxs[s];
        auto it = upper_bound(all(cur), ptr);
        ptr = *--it;
        o2.push_back(ptr);
    }
    reverse(all(o2));
    if (o1 == o2) cout << "unique" << endl;
    else cout << "ambiguous" << endl;
}
