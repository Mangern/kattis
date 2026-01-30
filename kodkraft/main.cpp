#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max()/ 8;

const int mxN = 1e6+6;

ll n, k;
vector<int> idx[mxN];
ll ttr[mxN];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x, --x;

        idx[x].push_back(i);
    }

    for (auto i : idx[0])ttr[i] = 1;

    for (ll j = 1; j < k; ++j) {
        ll minttr = INF;
        int minip = 0;
        int m = idx[j].size();
        for (int ip = 0; ip < m; ++ip) {
            int i = idx[j][ip];
            auto it = upper_bound(begin(idx[j-1]), end(idx[j-1]), i);
            if (it == begin(idx[j-1])) {
                it = --end(idx[j-1]);
            } else {
                --it;
            }

            ll dist = (i - *it + n) % n;
            ttr[i] = ttr[*it] + dist;
            if (ttr[i] < minttr) {
                minttr = ttr[i];
                minip = ip;
            }
        }

        for (int ip = (minip + 1) % m; ip != minip; ip = (ip + 1) % m) {
            int prvp = (ip + m - 1) % m;
            ll dist = (idx[j][ip] - idx[j][prvp] + n) % n;
            if (ttr[idx[j][prvp]] + dist < ttr[idx[j][ip]]) {
                ttr[idx[j][ip]] = ttr[idx[j][prvp]] + dist;
            }
        }
    }
    ll ans = INF;
    for (int i : idx[k-1]) {
        ans = min(ans, ttr[i]);
    }
    cout << ans << endl;
}
