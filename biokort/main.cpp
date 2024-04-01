#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 2e5+5;

ll n, m, k;
ll pop[mxN];

ll dp[1000000+5];

ll cost(ll cnt) {
    if (dp[cnt] != -1)return dp[cnt];
    ll res = cnt * k;
    for (int i = 0; i < n; ++i) {
        res += max(0LL, pop[i]-cnt) * m;
    }
    dp[cnt] = res;
    return res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;

    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cin >> pop[i];
    }

    ll lo = 0;
    ll hi = *max_element(pop, pop+n);

    while (lo < hi) {
        ll mid = (lo+hi)/2;

        int ai = mid;
        int bi = mid+1;
        ll a = cost(ai);
        ll b = cost(bi);
        while (b == a && bi + 1 <= hi) {
            b = cost(bi+1);
            ++bi;
        }
        while (b == a && ai - 1 >= lo) {
            a = cost(ai-1);
            --ai;
        }
        if (a == b) {
            cout << ai << " " << a << endl;
            return 0;
        }
        if (b < a) {
            lo = bi;
        } else {
            hi = ai;
        }
    }

    cout << lo << " " << cost(lo) << endl;
}
