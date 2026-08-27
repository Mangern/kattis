#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> items(n);
    for (auto &s: items) cin >> s;
    unordered_map<string, int> cat_order;
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        cat_order[s] = i;
    }
    unordered_map<string, int> item_order;
    for (int i = 0; i < k; ++i) {
        string cat;
        cin >> cat;
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            string s;
            cin >> s;
            item_order[s] = cat_order[cat];
        }
    }

    sort(begin(items), end(items), [&](const auto& s1, const auto& s2) {
        return item_order[s1] < item_order[s2];
    });
    for (auto s : items)cout << s << ' ';
    cout << endl;
}
