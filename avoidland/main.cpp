#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll> a) {
    sort(begin(a), end(a));

    ll ret = 0;
    for (ll i = 0; i < a.size(); ++i) {
        ret += abs(a[i] - (i+1));
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    cout << solve(a) + solve(b) << endl;
}
