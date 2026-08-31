#include <bits/stdc++.h>
using namespace std;

array<int, 4> ZERO = {-1, -1, -1, -1};

array<int, 4> inter(const array<int,4>& rect1, const array<int,4>& rect2) {
    auto [x11, y11, x12, y12] = rect1;
    auto [x21, y21, x22, y22] = rect2;
    if (x22 <= x11) return ZERO;
    if (x21 >= x12) return ZERO;
    if (y21 <= y12) return ZERO;
    if (y22 >= y11) return ZERO;

    int nx1 = max(x11, x21);
    int nx2 = min(x12, x22);
    int ny1 = min(y11, y21);
    int ny2 = max(y12, y22);
    return {nx1, ny1, nx2, ny2};
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int n;
        cin >> n;

        vector<array<int, 4>> rects(n);
        for (auto& [l,t,r,b] : rects) cin >> l >> t >> r >> b;
        array<int, 4> cur = rects[0];

        for (int i = 1; i < n; ++i) {
            cur = inter(cur, rects[i]);
        }
        cout << (cur[2] - cur[0])*(cur[1]-cur[3]) << '\n';
    }
}
