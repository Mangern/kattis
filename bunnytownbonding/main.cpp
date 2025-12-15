#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<ll> loc;
    string s;
    cin >> s;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B')loc.push_back(i);
    }
    int m = loc.size();

    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i + m <= n; ++i) {
        ll cur = 0;
        for (int j = i; j < i + m; ++j) {
            cur += abs(j - loc[j-i]);
        }
        ans=min(ans,cur);
    }
    cout << ans << endl;
}
