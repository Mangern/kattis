#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using build = array<ll, 2>;

ll area(vector<build> b) {
    ll ret = numeric_limits<ll>::max();
    ret = min(ret, (b[0][0] + b[2][0] + b[1][0]) * max(b[0][1], max(b[1][1], b[2][1])));
    ret = min(ret, (max(b[0][0], b[1][0]) + b[2][0]) * max(b[0][1] + b[1][1], b[2][1]));
    return ret;
}

void testCase() {
    vector<build> b(3);

    for (int i = 0; i < 3; ++i) {
        cin >> b[i][0] >> b[i][1];
    }
    sort(begin(b), end(b));

    ll ans = numeric_limits<ll>::max();

    do {
        for (int m = 0; m < 8; ++m) {
            vector<build> a;
            for (int j = 0; j < 3; ++j) {
                auto [x, y] = b[j];
                if ((m >>j) & 1) {
                    a.push_back({y, x});
                } else {
                    a.push_back({x, y});
                }
            }
            ans = min(ans, area(a));
        }
    } while (next_permutation(begin(b), end(b)));
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        testCase();
    }
}

