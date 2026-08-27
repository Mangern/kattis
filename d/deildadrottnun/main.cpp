#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> ans;

    for (ll i = 1; ; ++i) {
        if (n - i < 0) break;
        ans.push_back(i);
        n -= i;
    }

    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        if (n == 0) break;
        ++ans[i];
        --n;
    }
    assert(n == 0);
    cout << ans.size() << endl;
    for (auto x : ans)cout << x << " ";
    cout << endl;
}
