#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string_view sv(s);

    int n = s.length();

    unordered_map<string_view, int> count;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string_view sub = sv.substr(i, j - i + 1);
            ++count[sub];
        }
    }

    vector<pair<int, string_view>> ans;

    for (auto &[k,v] : count)ans.push_back({-v, k});

    sort(begin(ans), end(ans));

    for (auto [c, s] : ans) {
        cout << -c << " " << s << endl;
    }
}
