#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool fl = s[0] == 'a';

    vector<pair<int,int>> a(n);
    int mx = 0;
    for (auto &[x, y] : a) {
        cin >> x >> y;
        mx = max(mx, x+y);
    }

    int mx2 = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto [x, y] = a[i];
        if (x+y < mx)continue;
        if (fl) {
            if (x > mx2) {
                ans = i;
                mx2 = x;
            }
        } else {
            if (y > mx2) {
                ans = i;
                mx2 = y;
            }
        }
    }

    cout << ans+1 << endl;

    return 0;
}
