#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1005;

ll n;

ll a[mxN];

void send(ll a) {
    cout << a << endl;
}

void send(ll a, ll b) {
    cout << a << " " << b << endl;
}

ll dp[mxN][2];
pair<ll, bool> nxt[mxN][2];
pair<ll, ll> mov[mxN][2];
ll ret[mxN][2];

ll solve(ll i, bool hasa1 = false) {
    ll &r = dp[i][hasa1];
    if (r != -1) return r;

    if (i == 0) {
        // send a0+a1, return a0
        ll cur = a[1] + a[0];
        nxt[i][hasa1] = {2, true};
        mov[i][hasa1] = {a[0], a[1]};
        ret[i][hasa1] = a[0];
        return r = cur + solve(2, true);
    }

    if (hasa1) {
        if (i == n - 1) {
            // send a0 + a[n-1]
            nxt[i][hasa1] = {-1, 0};
            mov[i][hasa1] = {a[0], a[n-1]};
            ret[i][hasa1] = -1;
            return r = a[n-1];
        }
        // we have at least 3 ppl waiting: a0, a[i], a[i+1]
        // either send a[i], a[i+1] and return a1 
        // or send a0, a[i] and return a0
        ll alt1 = a[i+1] + a[1] + solve(i + 2, false);
        ll alt2 = a[i] + a[0] + solve(i + 1, true);
        if (alt1 < alt2) {
            nxt[i][hasa1] = {i + 2, false};
            mov[i][hasa1] = {a[i], a[i+1]};
            ret[i][hasa1] = a[1];
            return r = alt1;
        } else {
            nxt[i][hasa1] = {i + 1, true};
            mov[i][hasa1] = {a[0], a[i]};
            ret[i][hasa1] = a[0];
            return r = alt2;
        }
    } else {
        if (i == n) {
            // only a0 and a1 waiting
            nxt[i][hasa1] = {-1, false};
            mov[i][hasa1] = {a[0], a[1]};
            return r = a[1];
        }
        // send a0 and a[i], return a0?
        // send a0 and a[1], return a0
        ll alt1 = a[i] + a[0] + solve(i + 1, false);
        ll alt2 = a[1] + a[0] + solve(i, true);
        if (alt1 < alt2) {
            nxt[i][hasa1] = {i + 1, false};
            mov[i][hasa1] = {a[0], a[i]};
            ret[i][hasa1] = a[0];
            return r = alt1;
        } else {
            nxt[i][hasa1] = {i, true};
            mov[i][hasa1] = {a[0], a[1]};
            ret[i][hasa1] = a[0];
            return r = alt2;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = dp[i][1] = -1;
    }

    if (n <= 2) {
        cout << *max_element(a, a + n) << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        return 0;
    }

    ll ans = solve(0);

    ll i = 0;
    bool h = false;

    cout << ans << endl;

    while (1) {
        auto [x, y] = mov[i][h];
        cout << x << " " << y << endl;
        if (nxt[i][h].first == -1) break;
        cout << ret[i][h] << endl;
        auto [ni, nh] = nxt[i][h];
        i = ni;
        h = nh;
    }
}
