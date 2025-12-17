#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

bool fracless(const ii& a, const ii& b) {
    // a[0] / a[1] < b[0] / b[1]
    return a[0] * b[1] < b[0] * a[1];
}

int main() {
    ll f,r;
    for (;;) {
        cin >> f;
        if (!f)break;

        cin >> r;
        vector<ll> fs(f), rs(r);
        for (auto &x : fs) cin >> x;
        for (auto &x : rs) cin >> x;

        vector<ii> rats;

        for (auto x : fs) for (auto y : rs) {
            ll g = gcd(x,y);
            rats.push_back({y/g, x/g});
        }

        sort(begin(rats), end(rats), fracless);

        ii ans={-1,-1};
        for (int i = 1; i < rats.size(); ++i) {
            if (rats[i] == rats[i-1]) continue;
            ii nw = {rats[i-1][1] * rats[i][0], rats[i-1][0] * rats[i][1]};

            if (ans[0] == -1 || fracless(ans, nw))ans = nw;
        }

        cout << setprecision(2) << fixed << (double)ans[0] / (double)ans[1] << endl;
    }
}
