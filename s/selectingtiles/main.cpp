#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<int> need(26, 0);
    for (char c : t) ++need[c-'a'];
    vector<vector<int>> pref(26, vector<int>(1,0));

    int n = s.length();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            pref[j].push_back(pref[j].back() + (s[i] - 'a' == j));
        }
    }

    int ans = n + 2;
    for (int i = 0; i < n; ++i) {
        bool ok=1;
        int len = 1;

        for (int j = 0; j < 26; ++j) {
            int lo = i;
            int hi = n;

            while (lo < hi) {
                int mid = (lo + hi) / 2;
                int cnt = pref[j][mid+1] - pref[j][i];

                if (cnt >= need[j]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            if (pref[j][lo+1] - pref[j][i] < need[j]) {
                ok=0;
                break;
            }
            len = max(len, lo - i + 1);
        }

        if (ok)ans = min(ans, len);
    }
    if (ans == n + 2) ans = -1;
    cout << ans << endl;
}
