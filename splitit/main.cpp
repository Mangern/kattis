#include <bits/stdc++.h>
using namespace std;

const int mxK = 21;
int dp_rect[mxK*mxK];
int dp[mxK*mxK*mxK*mxK*mxK];

int grundy_rect(int n, int m) {
    if (n > m) swap(n, m);
    int key = n * mxK + m;
    if (dp_rect[key] != -1) 
        return dp_rect[key];

    int &r = dp_rect[key];

    if (n == 1) {
        assert(m > 1);
        if (m == 2) {
            return r = 0;
        }

        set<int> reach;
        for (int i = 2; i < m - 1; ++i) {
            int g1 = grundy_rect(n, i);
            int g2 = grundy_rect(n, m - i);
            int g = g1 ^ g2;
            reach.insert(g);
        }
        int mex = 0;
        while (reach.count(mex))++mex;
        return r = mex;
    }

    set<int> reach;

    for (int i = 1; i < n; ++i) {
        int g1 = grundy_rect(i, m);
        int g2 = grundy_rect(n - i, m);
        int g = g1 ^ g2;
        reach.insert(g);
    }
    for (int i = 1; i < m; ++i) {
        int g1 = grundy_rect(n, i);
        int g2 = grundy_rect(n, m - i);
        int g = g1 ^ g2;
        reach.insert(g);
    }
    int mex = 0;
    while (reach.count(mex))++mex;
    return r = mex;
}

// w1: width left of stick
// w2: width right of stick
// h1: height from roof to bottom of left side
// h2: height from roof to bottom of right side
// s: height from roof to top of stick
int grundy(int w1, int w2, int h1, int h2, int s) {
    if (w1 > w2) {
        swap(w1, w2);
        swap(h1, h2);
    }

    if (h1 == s && h2 == s) {
        return grundy_rect(h1, w1 + w2);
    }
    assert(s > 0);
    assert(h1 > s || h2 > s);
    int key = w1 * mxK * mxK * mxK * mxK
            + w2 * mxK * mxK * mxK
            + h1 * mxK * mxK
            + h2 * mxK
            + s;

    if (dp[key] != -1) return dp[key];
    int &r = dp[key];

    set<int> reach;

    // horizontal cut on left side
    for (int i = 1; h1 - i >= s; ++i) {
        // illegal move
        if (i == 1 && w1 == 1) continue;

        int g1 = grundy_rect(i, w1);
        int g2 = grundy(w1, w2, h1 - i, h2, s);
        reach.insert(g1 ^ g2);
    }
    // horizontal cut on right side
    for (int i = 1; h2 - i >= s; ++i) {
        if (i == 1 && w2 == 1) continue;
        int g1 = grundy_rect(i, w2);
        int g2 = grundy(w1, w2, h1, h2 - i, s);
        reach.insert(g1 ^ g2);
    }

    // horizontal cut above stick
    for (int i = 1; i < s; ++i) {
        if (i == 1 && w1 + w2 == 1) continue; // not even possible i think
        int g1 = grundy_rect(i, w1 + w2);
        int g2 = grundy(w1, w2, h1 - i, h2 - i, s - i);
        reach.insert(g1 ^ g2);
    }

    // vertical left side

    for (int i = 1; i < w1; ++i) {
        if (i == 1 && h1 == 1) continue; // ...
        int g1 = grundy_rect(i, h1);
        int g2 = grundy(w1 - i, w2, h1, h2, s);
        reach.insert(g1 ^ g2);
    }

    // vertical cut center
    if (!(w1 == 1 && h1 == 1) && !(w2 == 1 && h2 == 1)) {
        reach.insert(
            grundy_rect(w1, h1) ^ grundy_rect(w2, h2)
        );
    }

    // vertical right side
    for (int i = 1; i < w2; ++i) {
        if (i == 1 && h2 == 1) continue;
        int g1 = grundy_rect(i, h2);
        int g2 = grundy(w1, w2 - i, h1, h2, s);
        reach.insert(g1 ^ g2);
    }

    int mex = 0;
    while (reach.count(mex))++mex;
    return r = mex;
}

int main() {
    memset(dp_rect, -1, sizeof dp_rect);
    memset(dp, -1, sizeof dp);
    int t;
    cin >> t;
    while (t-->0) {
        int w, h, x, y, k;
        cin >> w >> h >> x >> y >> k;

        if (x == 0 || x == w) {
            swap(w, h);
            swap(x, y);
        }

        int ans;
        if (h == k) {
            ans = grundy_rect(x, h) ^ grundy_rect(w - x, h);
        } else {
            ans = grundy(x, w - x, h, h, h - k);
        }
        if (ans == 0) cout << 2 << endl;
        else cout << 1 << endl;
    }
}
