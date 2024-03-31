#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int n, k, l;

int main() {
    cin >> n >> k >> l;

    l *= 2;


    vector<ll> ans(k, 0);

    // total length traveled by color if you start at position i
    // with a certain color
    // and travel to the left
    // [pos][startcolor][querycolor]
    vector<vll> dp(k, vll(k, 0));

    // exit color if you start from pos i and go left with color j
    vector<int> exit_col(k, 0);

    ll dps = 0;

    ll last_pos = -1;
    int last_col;
    int last_idx;

    auto calculate_pairs = [&] (ll pos) {
        vector<vll> ndp(k, vll(k, 0));
        vector<int> nexit_col(k, 0);
        for (int start_col = 0; start_col < k; ++start_col) {
            for (int query_col = 0; query_col < k; ++query_col) {
                if (last_pos == -1) {
                    ndp[start_col][query_col] += pos * (start_col == query_col);
                } else {
                    ll mp = (last_pos + pos) / 2;

                    ll val = (pos - mp) * (start_col == query_col);

                    val += dp[(start_col+last_col)%k][query_col];

                    if (query_col == exit_col[(start_col+last_col)%k]) {
                        val += pos - mp;
                    }

                    ndp[start_col][query_col] = val;
                }
            }

            if (last_pos == -1) {
                nexit_col[start_col] = start_col;
            } else {
                nexit_col[start_col] = exit_col[(start_col + last_col) % k];
            }
        }
        return make_pair(ndp, nexit_col);
    };

    for (int i = 0; i < n; ++i) {
        ll d;
        int b;
        char c;
        cin >> d >> b >> c;

        d *= 2;

        auto [ndp, nexit_col] = calculate_pairs(d);

        if (c == 'L') {
            for (int kk = 0; kk < k; ++kk) {
                ans[kk] += ndp[b][kk];
            }
        } else {
            ans[b] += (l - d);

            dp = ndp;
            exit_col = nexit_col;

            last_pos = d;
            last_col = b;
            last_idx = i;
        }
    }

    cout << setprecision(1) << fixed;
    for (auto x : ans) {
        long double f = x;
        f /= 2.0;
        cout << f << endl;
    }

    return 0;
}
