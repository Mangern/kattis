#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int idx[5][9];

map<ll, ll> dp;

ll minleft(ll state) {
    if (dp.count(state)) {
        return dp[state];
    }

    ll ret = __builtin_popcountll(state);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (idx[i][j] == -1) continue;
            if (!((state >> idx[i][j])&1))continue;

            for (auto [ni, nj] : vector<pair<int,int>>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
                if (ni < 0 || ni >= 5 || nj < 0 || nj >= 9) continue;
                if (idx[ni][nj] == -1) continue;
                if (!((state >> idx[ni][nj])&1)) continue;
                int oi = i - (ni - i);
                int oj = j - (nj - j);
                if (oi < 0 || oi >= 5 || oj < 0 || oj >= 9) continue;
                if (idx[oi][oj] == -1) continue;
                if ((state >> idx[oi][oj])&1) continue;

                ll nstate = state;
                nstate ^= (1LL<<idx[i][j]);
                nstate ^= (1LL<<idx[ni][nj]);
                nstate ^= (1LL<<idx[oi][oj]);
                ret = min(ret, minleft(nstate));
            }
        }
    }

    dp[state] = ret;
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        ll state = 0;
        ll p = 0;
        for (int i = 0; i < 5; ++i) {
            string s;
            cin >> s;

            for (int j = 0; j < 9; ++j) {
                if (s[j] == '#') {
                    idx[i][j] = -1;
                    continue;
                }
                if (s[j] == 'o') {
                    state |= (1LL<<p);
                }
                idx[i][j] = p++;
            }
        }

        ll nstart = __builtin_popcountll(state);
        ll nend = minleft(state);

        cout << nend << " " << nstart - nend << endl;
    }
}
