//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using arr = array<ll, 2>;
using arrr = array<ll, 3>;
using vi = vector<int>;
using vll = vector<ll>;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x))

const int mxN = 105;

ll n, h, w;
arr books[mxN];
int choice[mxN];

int dp[mxN][901][351];

bool solve(int i, ll remw, ll remh, const vector<arr> &a, vi &ch, ll maxh) {
    if (i == a.size()) {
        return true;
    }

    if (dp[i][remw][remh] != -1) {
        return dp[i][remw][remh];
    }

    if (a[i][1] <= remw && a[i][0] <= h) {
        // set this book upright
        ch[i] = 0;
        if (solve(i + 1, remw - a[i][1], remh, a, ch, maxh)) {
            dp[i][remw][remh] = 1;
            return true;
        } 
    }

    if (a[i][1] <= remh && a[i][0] <= maxh) {
        // set this in the stack
        ch[i] = 1;
        if (solve(i + 1, remw, remh - a[i][1], a, ch, maxh)) {
            dp[i][remw][remh] = 1;
            return true;
        }
    }
    dp[i][remw][remh] = 0;
    return false;
}

bool check(int sel) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 901; ++j) {
            memset(dp[i][j], -1, sizeof dp[0][0]);
        }
    }
    vector<arr> rem;
    for (int i = 0; i < n; ++i) if (i != sel) {
        rem.push_back(books[i]);
    }

    if (books[sel][0] > w) return false;
    if (books[sel][1] > h) return false;

    ll remw = w - books[sel][0];
    ll remh = h - books[sel][1];

    vi ch(n - 1);

    if (!solve(0, remw, remh, rem, ch, books[sel][0])) return false;

    if (*min_element(begin(ch), end(ch)) > 0) return false;

    int ptr = 0;
    for (int i = 0; i < n; ++i) if (i != sel) {
        choice[i] = ch[ptr++];
    }
    choice[sel] = 1;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h >> w;

    for (int i = 0; i < n; ++i) {
        cin >> books[i][0] >> books[i][1];
    }

    bool done = 0;
    for (int i = 0; i < n; ++i) {
        if (check(i)) {
            done = 1;
            break;
        }
    }

    if (!done) {
        cout << "impossible" << endl;
        return 0;
    }

    vi up;
    vi down;
    for (int i = 0; i < n; ++i) {
        if (!choice[i]) {
            up.push_back(i);
        } else down.push_back(i);
    }

    cout << "upright";

    for (auto x : up) cout << " " << x+1;
    cout << endl;

    sort(begin(down), end(down), [&] (auto i, auto  j) {
        return books[i][0] > books[j][0];
    });

    cout << "stacked";
    for (auto x : down) cout << " " << x + 1;
    cout << endl;
}
