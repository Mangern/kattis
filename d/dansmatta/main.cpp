#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e4+5;
const string DIR = "UHNV";
const ll INF = INT_MAX;

ll dp[mxN][6];

int cid(char c) {
    switch (c) {
        case 'U':
            return 0;
        case 'H':
            return 1;
        case 'N':
            return 2;
        case 'V':
            return 3;
    }
    assert(false);
}

int dpid(char c1, char c2) {
    if (cid(c1)>cid(c2))return dpid(c2,c1);
    // 01, 02, 03, 12, 13, 23
    //  0   1   2   3   4   5
    if (cid(c1)==0)return cid(c2)-1;
    if (cid(c1)==1)return cid(c2)+1;
    return 5;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 6; ++j)dp[i][j] = INF;
    }

    dp[0][dpid('H', 'V')] = 0;

    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;

        if (s.length() == 2) {
            char c1 = s[0];
            char c2 = s[1];

            for (int di = 0; di < 4; ++di) {
                for (int dj = di + 1; dj < 4; ++dj) {
                    char d1 = DIR[di];
                    char d2 = DIR[dj];
                    // Transition from i-1,(d1,d2) to i,(c1,c2)

                    // d1 -> c1, d2 -> c2
                    ll& curr = dp[i][dpid(c1,c2)];
                    ll& prev = dp[i-1][dpid(d1,d2)];
                    curr = min(curr, prev + (d1 != c1) + (d2 != c2));

                    // d1 -> c2, d2 -> c1
                    curr = min(curr, prev + (d1 != c2) + (d2 != c1));
                }
            }
        } else {
            char c1 = s[0];

            for (char c2 : DIR) if (c2 != c1) {
                for (int di = 0; di < 4; ++di) {
                    for (int dj = di + 1; dj < 4; ++dj) {
                        char d1 = DIR[di];
                        char d2 = DIR[dj];

                        // d1 -> c1, d2 -> c2
                        ll& curr = dp[i][dpid(c1,c2)];
                        ll& prev = dp[i-1][dpid(d1,d2)];
                        curr = min(curr, prev + (d1 != c1) + (d2 != c2));

                        // d1 -> c2, d2 -> c1
                        curr = min(curr, prev + (d1 != c2) + (d2 != c1));
                    }
                }
            }
        }
    }

    ll ans = dp[n][0];
    for (ll i = 0; i < 6; ++i)ans = min(ans, dp[n][i]);

    cout << ans << endl;
}
