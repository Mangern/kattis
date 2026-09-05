#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    unordered_map<string, vector<pair<ll, ll>>> stocks;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        ll p, t;
        cin >> s >> p >> t;
        stocks[s].emplace_back(t,p);
    }
    ll ans = 0;
    for (auto& [s, v] : stocks) {
        sort(begin(v), end(v));

        ll mini = 1e15;
        ll here = 0;
        for (auto [t, p] : v) {
            mini = min(mini, p);
            here = max(here, p - mini);
        }
        ans += here;
    }
    cout << ans << endl;
}
