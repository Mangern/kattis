#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans;

    int cnt[3] = { 0, 0, 0};
    for (char c : s)++cnt[c-'a'];

    for (int i = 0; i < s.length(); ++i) {
        int mxc = 0;
        int mx = 0;
        for (int c = 0; c < 3; ++c) {
            if (ans.length() > 0 && c == ans.back() - 'a') continue;
            if (cnt[c] > mx) {
                mx = cnt[c];
                mxc = c;
            }
        }
        if (!mx) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        ans.push_back('a'+mxc);
        --cnt[mxc];
    }
    cout << ans << endl;
}
