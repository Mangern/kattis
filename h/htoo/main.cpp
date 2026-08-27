#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<char, ll> parse(string s) {
    int n = s.length();
    map<char, ll> res;
    for (int i = 0; i < n;) {
        assert('A' <= s[i] && s[i] <= 'Z');
        int j;

        for (j = i + 1; j < n; ++j) {
            if ('A' <= s[j] && s[j] <= 'Z') break;
        }

        if (j == i + 1) {
            res[s[i]] += 1;
        } else {
            res[s[i]] += stoi(s.substr(i+1,j-i-1));
        }
        i = j;
    }
    return res;
}

int main() {
    string s, t;
    cin >> s;
    ll k;
    cin >> k;
    cin >> t;

    auto cnt1 = parse(s);
    auto cnt2 = parse(t);

    for (auto &[_, v] : cnt1) v*= k;

    ll ans = numeric_limits<ll>::max();
    for (auto [k, v] : cnt2) {
        ans= min(ans, cnt1[k] / v);
    }
    cout << ans << endl;
}
