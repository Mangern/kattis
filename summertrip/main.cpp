#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<vector<int>> idx(26);

    for (int i = 0; i < n; ++i) {
        idx[s[i]-'a'].push_back(i);
    }
    ll ans = 0;
    for (int c = 0; c < 26; ++c) {
        for (int i = 0; i < idx[c].size(); ++i) {
            int fst = idx[c][i];
            int lst = (i + 1 < idx[c].size() ? idx[c][i+1] : n);
            for (int d = 0; d < 26; ++d) if (d != c) {
                // does idx[d] contain an entry > fst and < lst?
                auto it = upper_bound(begin(idx[d]), end(idx[d]), fst);
                if (it != end(idx[d]) && *it < lst) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;
}
