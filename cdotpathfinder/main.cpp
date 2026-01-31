#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {

        vector<ii> prs;

        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            ll a, b;
            cin >> b >> a;
            prs.push_back({a,b});
        }
        vector<int> idx(k);
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&] (auto i1, auto i2) {
            // p1[0]/p1[1] < p2[0]/p2[1]
            auto [a1, b1] = prs[i1];
            auto [a2, b2] = prs[i2];

            return a1 * b2 < b1 * a2;
        });
        cout << idx[0]+1 << endl;
    }
}
