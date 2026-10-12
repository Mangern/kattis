#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll> divs;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i < n) divs.push_back(n / i);
        }
    }
    sort(begin(divs), end(divs));
    ll m = divs.size();
    vector<ll> dp(m, 0);
    dp[0] = 1;
    for (ll i = 0; i < m; ++i) {
        for (ll j = i+1; j < m; ++j) {
            if (divs[j] % divs[i] == 0) {
                dp[j] += dp[i];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[m-1] << '\n';
}
