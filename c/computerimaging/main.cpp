#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

int main() {
    ll n, m;
    cin >> n >> m;

    ll ans = 0;

    vector<ll> ts(m, 0);
    vector<ll> free_at(m, 0);

    for (int i = 0; i < m; ++i) {
        cin >> ts[i];
    }

    for (int _ = 0; _ < n; ++_) {
        int mini = 0;
        for (int i = 0; i < m; ++i) {
            if (free_at[i] + ts[i] < free_at[mini] + ts[mini]) {
                mini = i;
            }
        }
        ans = max(ans, free_at[mini] + ts[mini]);
        free_at[mini] += ts[mini];
    }

    cout << ans << endl;
}
