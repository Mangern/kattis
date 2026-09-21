#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<ll>> chunks;
    chunks.emplace_back();

    for (int i = 0; i < n; ++i) {
        if (a[i] < m) {
            chunks.emplace_back();
            continue;
        }
        chunks.back().push_back(a[i]);
    }

    ll ans = 0;
    for (auto &chunk : chunks) {
        if (chunk.empty()) continue;
        vector<ll> slft(chunk.size()), srgt(chunk.size());

        ll s = 0;

        for (int i = 0; i < chunk.size(); ++i) {
            s += chunk[i];
            slft[i] = s;
            if (chunk[i] == m) {
                s = 0;
            }
        }
        s = 0;
        for (int i = (int)chunk.size() - 1; i >= 0; --i) {
            srgt[i] = s;
            s += chunk[i];
            if (chunk[i] == m) {
                s = 0;
            }
        }
        for (int i = 0; i < chunk.size(); ++i) {
            if (chunk[i] == m) {
                ans = max(ans, slft[i] + srgt[i]);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) solve();
}
