#include <bits/stdc++.h>
using namespace std;

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;

        vector<vector<bool>> cov(505, vector<bool>(505, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            for (int x = a; x < c; ++x) {
                for (int y = b; y < d; ++y) {
                    if (!cov[x][y])++ans;
                    cov[x][y] = 1;
                }
            }
        }

        cout << ans << "\n";
    }
}
