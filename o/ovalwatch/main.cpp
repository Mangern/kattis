#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ii>> a(n);

    for (int i = 0; i < k; ++i) {
        ll x, y;

        cin >> x >> y;
        a[x].push_back({y, x+1});
        a[x+1].push_back({y, x});
    }
    for (int i = 0; i < n; ++i) {
        sort(begin(a[i]), end(a[i]));
    }

    for (int i = 0; i < n; ++i) {
        ll d = 0;
        int idx = i;

        for (;;) {
            auto it = lower_bound(begin(a[idx]), end(a[idx]), ii{d, 0});

            if (it == end(a[idx])) {
                break;
            }
            d = (*it)[0]+1;
            idx = (*it)[1];
        }
        cout << idx << " ";
    }
    cout << endl;
}
