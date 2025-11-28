#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int m;
    cin >> m;
    int ans = 0;

    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;

        int pos = 0;
        for (;;) {
            auto res = t.find(s, pos);
            if (res == string::npos) break;
            ++ans;
            pos = res+1;
        }
    }
    cout << ans << endl;
}
