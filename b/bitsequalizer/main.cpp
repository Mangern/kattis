#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case " << tc << ": ";
        string s, t;
        cin >> s >> t;
        int n = s.length();

        int need_1 = 0, have_1 = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') ++have_1;
            if (t[i] == '1') ++need_1;
        }

        int ans = 0;
        // Optimal switches first
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?' && t[i] == '1' && have_1 < need_1) {
                s[i] = '1';
                ++have_1;
                ++ans;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                if (have_1 < need_1) {
                    s[i] = '1';
                    ++have_1;
                    ++ans;
                } else {
                    s[i] = '0';
                    ++ans;
                }
            }
        }

        if (have_1 > need_1) {
            cout << -1 << '\n';
            continue;
        }

        int n01 = 0, n10 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0' && t[i] == '1') {
                ++n01;
            }
            if (s[i] == '1' && t[i] == '0') {
                ++n10;
            }
        }
        assert(n01 >= n10);
        ans += n10;
        ans += n01 - n10;
        cout << ans << '\n';
    }
}
