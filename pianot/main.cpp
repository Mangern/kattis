#include <bits/stdc++.h>
using namespace std;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x)) 

const int mxK = 15;

int n, k;
string s, uniq;

int cnt[mxK][mxK];
int dp[1<<mxK];
int solve(int mask) {
    int &r = dp[mask];

    if (r != -1) return r;

    if (mask == 0) {
        r = 0;
        return r;
    }

    r = INT_MAX;
    FORMASK(i, mask) {
        r = min(r, solve(mask ^ (1<<i)));
    }

    FORMASK(i, mask) {
        FORMASK(j, (~mask)&((1<<k)-1)) {
            r += cnt[i][j];
        }
    }
    return r;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> s;

    uniq = s;
    sort(begin(uniq), end(uniq));
    uniq.erase(unique(begin(uniq), end(uniq)), end(uniq));

    n = s.length();
    k = uniq.length();

    for (int i = 1; i < n; ++i) {
        if (s[i-1] == s[i]) continue;
        int a = uniq.find(s[i-1]);
        int b = uniq.find(s[i]);
        ++cnt[a][b];
        ++cnt[b][a];
    }

    cout << solve((1<<k)-1) << endl;
}
