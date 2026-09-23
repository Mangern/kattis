#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    array<int, 10> cnt = {0};
    for (char c : s) {
        ++cnt[c-'0'];
    }

    int len = cnt[0] + 2;
    int ld = 0;

    for (int i = 1; i <= 9; ++i) {
        if (cnt[i] + 1 < len) {
            len = cnt[i] + 1;
            ld = i;
        }
    }

    if (ld == 0) {
        // ans looks like 1 0000...0
        string ans(len,'0');
        ans[0] = '1';
        cout << ans << endl;
        return 0;
    }

    cout << string(len, '0'+ld) << endl;
}
