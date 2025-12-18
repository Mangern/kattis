#include <bits/stdc++.h>
using namespace std;
using tup = array<double,3>;

int main() {
    int n;
    cin >> n;
    vector<tup> pts(n);
    for (auto &[x,y,r] : pts)cin >> x >> y >> r;

    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) if (j != i) {
            auto [x1,y1,r1] = pts[i];
            auto [x2,y2,r2] = pts[j];

            if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)-1e-8 <= r2 * r2)++ans;
        }
        cout << ans << endl;
    }
}
