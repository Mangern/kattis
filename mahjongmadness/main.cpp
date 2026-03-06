#include <bits/stdc++.h>
using namespace std;

bool istrip(int a, int b, int c) {
    if (a == b && b == c) return true;
    return a + 1 == b && b + 1 == c;
}

int score(vector<int> hand, int xx) {
    assert(hand.size() == 14);
    sort(begin(hand), end(hand));

    int sc = 1;
    for (int i = 0; i < 14; ++i)sc += (hand[i] == xx);

    for (int i = 0; i < 14; ++i) {
        for (int j = i + 1; j < 14; ++j) {
            if (hand[i] != hand[j]) break;

            for (int a = 0; a < 14; ++a) if (a != i && a != j) {
            for (int b = a + 1; b < 14; ++b) if (b != i && b != j) {
            for (int c = b + 1; c < 14; ++c) if (c != i && c != j) {
                if (!istrip(hand[a], hand[b], hand[c])) continue;
                for (int x = 0; x < 14; ++x) {
                    if (x == i || x == j || x == a || x == b || x == c) continue;
                for (int y = x + 1; y < 14; ++y) {
                    if (y == i || y == j || y == a || y == b || y == c) continue;
                for (int z = y + 1; z < 14; ++z) {
                    if (z == i || z == j || z == a || z == b || z == c) continue;
                    if (!istrip(hand[x], hand[y], hand[z])) continue;
                    int mask = (1<<i)|(1<<j)|(1<<a)|(1<<b)|(1<<c)|(1<<x)|(1<<y)|(1<<z);
                    assert(__builtin_popcount(mask)==8);
                    for (int p = 0; p < 14; ++p) {
                    for (int q = p + 1; q < 14; ++q) {
                    for (int r = q + 1; r < 14; ++r) {
                        if (((mask >> p)&1)||((mask>>q)&1)||((mask>>r)&1)) continue;
                        mask |= 1<<p;
                        mask |= 1<<q;
                        mask |= 1<<r;
                        assert(__builtin_popcount(mask)==11);
                        if (!istrip(hand[p], hand[q], hand[r])) {
                            mask ^= 1<<p;
                            mask ^= 1<<q;
                            mask ^= 1<<r;
                            continue;
                        }
                        for (int l = 0; l < 14; ++l) {
                            if ((mask >> l) & 1) continue;
                        for (int m = l + 1; m < 14; ++m) {
                            if ((mask >> m) & 1) continue;
                        for (int n = m + 1; n < 14; ++n) {
                            if ((mask >> n) & 1) continue;
                            if (!istrip(hand[l], hand[m], hand[n])) continue;
                            return sc;
                        }}}
                        mask ^= 1<<p;
                        mask ^= 1<<q;
                        mask ^= 1<<r;
                    }}}
                }}}
            }}}
        }
    }
    return 0;
}

int main() {
    int x;
    cin >> x;

    vector<int> inithand(14);
    vector<int> cnt(10, 0);
    for (auto &a : inithand) {
        cin >> a;
        ++cnt[a];
    }
    vector<double> prob(10);

    for (int i = 1; i <= 9; ++i) {
        prob[i] = double(4 - cnt[i]) / (double)22;
    }
    vector<bool> vis(10, 0);

    double ans = 0.0;
    for (int i = 0; i < 14; ++i) {
        if (vis[inithand[i]]) continue;
        vis[inithand[i]] = 1;

        double cur = 0.0;
        for (int j = 1; j <= 9; ++j) {
            int old = inithand[i];
            inithand[i] = j;
            double res = score(inithand, x);
            // cout << old << " -> " << j << ": " << res << endl;
            cur += res * prob[j];
            inithand[i] = old;
        }
        // cout << "For choice " << inithand[i] << ": " << cur << endl;
        ans = max(ans, cur);
    }
    cout << setprecision(12) << fixed << ans << endl;

}
