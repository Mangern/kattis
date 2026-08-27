#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s(n, '0');
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v)s[i] = '1';
    }

    int ans = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == '0') {
            ++i;
            continue;
        }

        int j;
        for (j = i; j < n; ++j) {
            if (s[j] == '0') break;
        }
        ans=max(ans, j - i);
        i = j;
    }
    cout << ans << endl;
}
