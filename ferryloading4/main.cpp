#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void testCase() {
    ll l, m;
    cin >> l >> m; l *= 100;

    queue<ll> lft, rgt;

    for (int i = 0; i < m; ++i) {
        ll x; string s;
        cin >> x >> s;

        if (s[0] == 'l')lft.push(x);
        else rgt.push(x);
    }
    ll ans = 0;

    bool fl = 1;

    while (lft.size() || rgt.size()) {
        if (fl) {
            ll rem = l;
            while (lft.size() && lft.front() <= rem) {
                rem -= lft.front();
                lft.pop();
            }
            ++ans;
        } else {
            ll rem = l;
            while (rgt.size() && rgt.front() <= rem) {
                rem -= rgt.front();
                rgt.pop();
            }
            ++ans;
        }
        fl = !fl;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0)testCase();
}
