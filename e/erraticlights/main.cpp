#include <bits/stdc++.h>
using namespace std;
using state = array<int, 3>;

state normalize(const state& s) {
    state ret = s;
    if (ret[2] > ret[1])
        swap(ret[1], ret[2]);
    if (ret[1] > ret[0])
        swap(ret[0], ret[1]);
    if (ret[2] > ret[1])
        swap(ret[1], ret[2]);
    return ret;
}

double dp[101*101*101+5];

int key(const state& s) {
    auto [r, g, b] = s;
    return r * 101 * 101 + g * 101 + b;
}

double E(const state& s) {
    auto [r, g, b] = s;
    if (g == 0) {
        return 0.0;
    }
    int k = key(s);
    double &ret = dp[k];
    if (ret >= 0.0) return dp[k];

    if (b == 0) {
        state s1 = normalize(state{r + 1, g - 1, 0});
        ret = 3.0 + E(s1);
    } else {
        state s1 = normalize(state{r + 1, g, b - 1});
        state s2 = normalize(state{r, g + 1, b - 1});
        ret = 1.5 + 0.5 * (E(s1) + E(s2));
    }
    return ret;
}

int main() {
    for (int i = 0; i < sizeof(dp) / sizeof(double); ++i) {
        dp[i] = -1.0;
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0, g = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'r')++r;
        if (s[i] == 'g')++g;
        if (s[i] == 'b')++b;
    }
    double ans = E(normalize(state{r,g,b}));
    cout << setprecision(8) << fixed << ans << endl;
}
