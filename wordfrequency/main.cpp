#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    unordered_map<string, int> freq;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s.length() >= m)++freq[s];
    }

    vector<pair<int, string>> aa;
    for (auto [ky, v] : freq)aa.push_back({-v, ky});

    int ml = min(k, int(aa.size()));

    sort(begin(aa), end(aa));
    for (int i = 0; i < ml; ++i) {
        cout << aa[i].second << " " << -aa[i].first << endl;
    }
}
